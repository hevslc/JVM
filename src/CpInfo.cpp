#include "CpInfo.h"

float ConstantPool::getFloat(u4 bytes){
	int s = ((bytes >> 31) == 0) ? 1 : -1;
	int e = (bytes >> 23) & 0xff;
	int m = (e == 0) ? (bytes & 0x7fffff) << 1 : (bytes & 0x7fffff) | 0x800000;
	float v = s*m*pow(2, exp(1)-150);
	if(bytes == 0x7f800000) return std::numeric_limits<float>::infinity();
	else if(bytes ==  0xff800000) return -std::numeric_limits<float>::infinity();
	else return v;
}

double ConstantPool::getDouble(u4 highBytes, u4 lowBytes){
	uint64_t hb = highBytes;
	uint64_t l = (hb << 32) | (long)lowBytes;
	return reinterpret_cast<double&>(l);
}

long ConstantPool::getLong(u4 highBytes, u4 lowBytes){
	uint64_t hb = highBytes;
	uint64_t l = (hb << 32) | (long)lowBytes;
	return reinterpret_cast<long&>(l);
}

ConstantPool::ConstantPool(std::ifstream& f, u2 constantPoolCount){
	for(int i=0; i<constantPoolCount-1; i++){
		bool largeN = false;
		Cpinfo *cpinfo = new Cpinfo;
		cpinfo->tag = r1(f);
		switch(cpinfo->tag){
			case CONSTANT_Class:
				cpinfo->Class.nameIndex = r2(f);
				break;
			case CONSTANT_Fieldref:
			case CONSTANT_Methodref:
			case CONSTANT_InterfaceMethodref:
				cpinfo->FieldMethInter.classIndex = r2(f);
				cpinfo->FieldMethInter.nameTypeIndex = r2(f);
				break;
			case CONSTANT_String:
				cpinfo->String.stringIndex = r2(f);
				break;
			case CONSTANT_Integer:
				cpinfo->Integer.bytes = r4(f);
				cpinfo->Integer.nint = int(cpinfo->Integer.bytes);
				break;
			case CONSTANT_Float:
				cpinfo->Float.bytes = r4(f);
				cpinfo->Float.nfloat = getFloat(cpinfo->Float.bytes);
				break;
			case CONSTANT_Long:
				cpinfo->Long.highBytes = r4(f);
				cpinfo->Long.lowBytes = r4(f);
				cpinfo->Long.nlong = getLong(cpinfo->Long.highBytes, cpinfo->Long.lowBytes);
				i++;
				largeN = true;
				break;
			case CONSTANT_Double:
				cpinfo->Double.highBytes = r4(f);
				cpinfo->Double.lowBytes = r4(f);
				cpinfo->Double.ndouble = getDouble(cpinfo->Double.highBytes, cpinfo->Double.lowBytes);
				i++;
				largeN = true;
				break;
			case CONSTANT_NameAndType:
				cpinfo->NameAndType.nameIndex = r2(f);
				cpinfo->NameAndType.descriptorIndex = r2(f);
				break;
			case CONSTANT_Utf8:
				cpinfo->Utf8.lenght = r2(f);
				cpinfo->Utf8.bytes = new u1[cpinfo->Utf8.lenght];
				for(int j=0; j<cpinfo->Utf8.lenght; j++) cpinfo->Utf8.bytes[j] = r1(f);
				break;
			default:
				break;
		}
		push_back(*cpinfo);
		if(largeN) push_back(Cpinfo());
	}
}

std::string ConstantPool::Bytes2Str(Cpinfo cpi){
	std::string name;
	for(int i=0; i<cpi.Utf8.lenght; i++) name.push_back(char(cpi.Utf8.bytes[i]));
	return name;
}

std::string ConstantPool::getUtf8Str(u2 idxUtf8){
	return Bytes2Str(at(idxUtf8));
}

std::string ConstantPool::getUtf8Class(u2 idxClass){
	return getUtf8Str(at(idxClass).Class.nameIndex-1);
}

std::string ConstantPool::getDescriptor(u2 idxNameType){
	return getUtf8Str(at(idxNameType).NameAndType.descriptorIndex-1);
}

std::string ConstantPool::getNNameAndType(u2 idxNameType){
	return getUtf8Str(at(idxNameType).NameAndType.nameIndex-1);
}

// std::string ConstantPool::getDouble(u2 idxDouble){
// 	return getUtf8Str(at(idxDouble).NameAndType.nameIndex-1);
// }

void ConstantPool::print(std::ostream& out){
	out << "\n__________________ConstantPool__________________" << std::endl;
	out << std::showbase;
	for (auto cp : *this){
		out << "..................." << std::endl;
		if(cp.tag) out << "Tag..............: " << std::dec << int(cp.tag);
		switch(cp.tag){
			case CONSTANT_Class:
				out << " (Class)" << std::endl;
				out << "Name.............: " << getUtf8Str(cp.Class.nameIndex-1) << std::endl;
				break;
			case CONSTANT_Fieldref:
				out << " (Field)" << std::endl;
				out << "Class Name.......: " << getUtf8Class(cp.FieldMethInter.classIndex-1) << std::endl;
				out << "Name and Type....: " << getNNameAndType(cp.FieldMethInter.nameTypeIndex-1);
				out << "  :  " << getDescriptor(cp.FieldMethInter.nameTypeIndex-1) << std::endl;
				break;			
			case CONSTANT_Methodref:
				out << " (Method)" << std::endl;
				out << "Class Name.......: " << getUtf8Class(cp.FieldMethInter.classIndex-1) << std::endl;
				out << "Name and Type....: " << getNNameAndType(cp.FieldMethInter.nameTypeIndex-1);
				out << "  :  " << getDescriptor(cp.FieldMethInter.nameTypeIndex-1) << std::endl;
				break;			
			case CONSTANT_InterfaceMethodref:
				out << " (Interface)" << std::endl;
				out << "Class Name.......: " << getUtf8Class(cp.FieldMethInter.classIndex-1) << std::endl;
				out << "Name and Type....: " << getNNameAndType(cp.FieldMethInter.nameTypeIndex-1);
				out << "  :  " << getDescriptor(cp.FieldMethInter.nameTypeIndex-1) << std::endl;
				break;
			case CONSTANT_String:
				out << " (String)" << std::endl;
				out << "Name.............: " << getUtf8Str(cp.String.stringIndex-1) << std::endl;
				break;
			case CONSTANT_Integer:
				out << " (Integer)" << std::endl;
				out << "Number...........: " << std::dec << cp.Integer.nint  << std::endl;
				break;
			case CONSTANT_Float:
				out << " (Float)" << std::endl;
				out << "Number...........: " << cp.Float.nfloat << std::endl;
				break;
			case CONSTANT_Long:
				out << " (Long)" << std::endl;
				out << "High Bytes.......: " << std::hex << cp.Long.highBytes << std::endl;
				out << "Low Bytes........: " << std::hex << cp.Long.lowBytes << std::endl;
				out << "Number...........: " << std::dec << cp.Long.nlong << std::endl;
				break;
			case CONSTANT_Double:
				out << " (Double)" << std::endl;
				out << "High Bytes.......: " << std::hex << cp.Double.highBytes << std::endl;
				out << "Low Bytes........: " << std::hex << cp.Double.lowBytes << std::endl;				
				out << "Number...........: " << cp.Double.ndouble << std::endl;
				break;
			case CONSTANT_NameAndType:
				out << " (NameAndType)" << std::endl;
				out << "Name and Type....: " << getUtf8Str(cp.NameAndType.nameIndex-1);
				out << "  :  " << getUtf8Str(cp.NameAndType.descriptorIndex-1) << std::endl;	
				break;
			case CONSTANT_Utf8:
				out << " (Utf8)" << std::endl;
				out << "Bytes............: " << Bytes2Str(cp) << std::endl;	
				break;
			default:
				break;
		}
	}
}
