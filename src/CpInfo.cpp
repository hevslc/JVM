#include "CpInfo.h"

float ConstantPool::getFloat(u4 bytes){
	if(bytes == 0x7f800000) return std::numeric_limits<float>::infinity();
	else if(bytes ==  0xff800000) return -std::numeric_limits<float>::infinity();
	else if((bytes > 0xff800001) & (bytes <  0xffffffff)) return (float)bytes;
	else if((bytes > 0xff800001) & (bytes <  0xffffffff)) return (float)bytes;
	else{
		int s = ((bytes >> 31) == 0) ? 1 : -1;
		int e = bytes >> 23
		int e = e & 0xff;
		int m = (e == 0) ? (bytes & 0x7fffff) << 1 : (bytes & 0x7fffff) | 0x800000;
		return (float)(s*m*pow(2, exp(1)-150));
	}
}

float ConstantPool::getDouble(u4 highBytes, u4 lowBytes){
	long l = (long)high_bytes << 32;
	l = l | (long)low_bytes;
	if(l == 0x7ff0000000000000L) return std::numeric_limits<double>::infinity();
	else if(l ==  0xfff0000000000000L) return -std::numeric_limits<double>::infinity();
	else if((l > 0x7ff0000000000001L) & (l <  0x7fffffffffffffffL)) return (float)l;
	else if((l > 0xfff0000000000001L) & (l <  0xffffffffffffffffL)) return (float)l;
	else{
		int s = ((l >> 63) == 0) ? 1 : -1;
		int e = (int)(l >> 52);
		int e = (int)(e & 0x7ffL);
		long m = (e == 0) ? (l & 0xfffffffffffffL) << 1 : (l & 0xfffffffffffffL) | 0x10000000000000L;
		return (double)(s*m*pow(2, exp(1)-1075));
	}
}

long ConstantPool::getLong(u4 highBytes, u4 lowBytes){
	long l = (long)high_bytes << 32;
	return (l | (long)low_bytes);
}

//! Método rconstantPool
/*!
	Método lê toda a tabela de constantes do arquivo .class armazenando as informações 
	no objeto da classe cpinfo em seus respectivos atributos.
	Na cada estrutura lida é da forma 
	~~~~~{.cpp}
	cp_info {
	u1 tag;
	u1 info[ ];
	}
	~~~~~
	Portanto, a tribuição dos atributos é feita verificando a tag, o qual 
	define o tipo da informação em cp_info.
	\param f Arquivo .class a ser lido.
	\sa #CONSTANT_Class, #CONSTANT_Fieldref, #CONSTANT_Methodref, #CONSTANT_InterfaceMethodref,
		#CONSTANT_String, #CONSTANT_Integer, #CONSTANT_Float, #CONSTANT_Long, #CONSTANT_Double,
		#CONSTANT_NameAndType, #CONSTANT_Utf8
*/ 
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
				break;
			case CONSTANT_Double:
				cpinfo->LongDouble.highBytes = r4(f);
				cpinfo->LongDouble.lowBytes = r4(f);
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

std::string ConstantPool::getUtf8Str(u2 idx){
	std::string name;
	for(int i=0; i<at(idx).Utf8.lenght; i++) name.push_back(char(at(idx).Utf8.bytes[i]));
	return name;
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


// PARA TESTE
void ConstantPool::print(){
	std::cout << "__________________ConstantPool__________________" << std::endl;
	for (auto cp : *this){
		std::cout << "..................." << std::endl;
		switch(cp.tag){
			case CONSTANT_Class:
				std::cout << "Tag..............: " << (int)CONSTANT_Class << " (Class)" << std::endl;
				std::cout << "Name.............: " << getUtf8Str(cp.Class.nameIndex-1) << std::endl;
				break;
			case CONSTANT_Fieldref:
				std::cout << "Tag..............: " << (int)CONSTANT_InterfaceMethodref << " (Field)" << std::endl;
				std::cout << "Class belonging:.: " << getUtf8Class(cp.FieldMethInter.classIndex-1);
				std::cout << "\nName.............: " << getNNameAndType(cp.FieldMethInter.nameTypeIndex-1);
				std::cout << "\nType.............: " << getDescriptor(cp.FieldMethInter.nameTypeIndex-1) << std::endl;
				break;			
			case CONSTANT_Methodref:
				std::cout << "Tag..............: " << (int)CONSTANT_InterfaceMethodref << " (Method)" << std::endl;
				std::cout << "Class belonging:.: " << getUtf8Class(cp.FieldMethInter.classIndex-1);
				std::cout << "\nName.............: " << getNNameAndType(cp.FieldMethInter.nameTypeIndex-1);
				std::cout << "\nType.............: " << getDescriptor(cp.FieldMethInter.nameTypeIndex-1) << std::endl;
				break;			
			case CONSTANT_InterfaceMethodref:
				std::cout << "Tag..............: " << (int)CONSTANT_InterfaceMethodref << " (Interface)" << std::endl;
				std::cout << "Class belonging:.: " << getUtf8Class(cp.FieldMethInter.classIndex-1);
				std::cout << "\nName.............: " << getNNameAndType(cp.FieldMethInter.nameTypeIndex-1);
				std::cout << "\nType.............: " << getDescriptor(cp.FieldMethInter.nameTypeIndex-1) << std::endl;
				break;
			case CONSTANT_String:
				std::cout << "Tag..............: " << (int)CONSTANT_String << " (String)" << std::endl;
				std::cout << "Name.............: " << getUtf8Str(cp.String.stringIndex-1) << std::endl;
				break;
			case CONSTANT_Integer:
				std::cout << "Tag..............: " << (int)CONSTANT_Integer << " (Integer)" << std::endl;
				std::cout << "Number...........: " << (int)cp.Integer.nint  << std::endl;
				break;
			case CONSTANT_Float:
				std::cout << "Tag..............: " << (float)CONSTANT_Float << " (Float)" << std::endl;
				std::cout << "Number...........: " << (float)cp.Float.nfloat << std::endl;
				break;
			case CONSTANT_Long:
				std::cout << "Tag..............: " << (int)CONSTANT_Long << " (Long)" << std::endl;
				std::cout << "Number...........: " << (long)cp.Long.nlong << std::endl;
			/*case CONSTANT_Double:
				if(cp.tag == CONSTANT_Double)
					std::cout << "Tag..............: " << (int)CONSTANT_Float << " (Double)" << std::endl;
				uint64_t d = (uint64_t)cp.LongDouble.highBytes << 32;
				d = d | (uint64_t)cp.LongDouble.lowBytes;
				std::cout << "Number...........: " << (int)cp.IntegerFloat.bytes << std::endl;
				break;*/
			//case CONSTANT_NameAndType:
				// std::cout << "nameIndex: "  << cp.NameAndType.nameIndex << std::endl;
				// std::cout << "descriptorIndex: "  << cp.NameAndType.descriptorIndex << std::endl;
			//	break;
			//case CONSTANT_Utf8:
				// std::cout << " (Utf8)" << std::endl;
				// std::cout << "Bytes............: ";
				// cp.Utf8.print();
			//	break;
			default:
				break;
		}
	}
}