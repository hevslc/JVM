#include "AttributeInfo.h"


void AttributeInfo::generalInfo(u2 idx, std::ifstream& f, std::string name){ 
	attributeNameIndex = idx;
	attributeLength = r4(f);
	this->name = name;
}

SourceFile::SourceFile(u2 idx, std::ifstream& f, std::string name){
	generalInfo(idx, f, name);
	sourcefileIndex = r2(f);
}

Classes::Classes(std::ifstream& f, u2 len):
std::vector<ClassesInfo*>(len){
    for (u2 i = 0; i < size(); i++){
        at(i) = new ClassesInfo();
        at(i)->innerClassInfoIndex = r2(f);
        at(i)->outerClassInfoIndex = r2(f);
        at(i)->innerNameIndex = r2(f);
        at(i)->innerClassAccessFlags = r2(f);
        at(i)->acessFlags.set(at(i)->innerClassAccessFlags);
    }
}

InnerClasses::InnerClasses(u2 idx, std::ifstream& f, std::string name){
	generalInfo(idx, f, name);
	numberOfClasses = r2(f);
	classes = new Classes(f, numberOfClasses);
}

template<typename T>
ConstantValue<T>::ConstantValue(u1 tag, u2 idx, u4 l, std::string name, T v){
	attributeNameIndex = idx;
	attributeLength = l;
	this->name = name;
	value = v;
	tagValue = tag;
}

ExceptionTable::ExceptionTable(std::ifstream& f, u2 len):
std::vector<ExceptionTableInfo*>(len){ 
    for (u2 i = 0; i < size(); i++){
        at(i) = new ExceptionTableInfo();
        at(i)->startPc = r2(f);
        at(i)->endPc = r2(f);
        at(i)->handlerPc = r2(f);
        at(i)->catchType = r2(f);
    }
}

Code::Code(u2 idx, std::ifstream& f, ConstantPool constantPool, std::string name){
	generalInfo(idx, f, name);
	maxStack = r2(f);
	maxLocals = r2(f);
	codeLength = r4(f);
	code = new u1[codeLength];
	for(u2 i=0; i<codeLength; i++)  code[i] = r1(f);
	exceptionTableLength = r2(f);
	exceptionTable = new ExceptionTable(f, exceptionTableLength);
	attributesCount = r2(f);
	attributes = new Attributes(f, attributesCount, constantPool);
}

Exceptions::Exceptions(u2 idx, std::ifstream& f, std::string name){
	generalInfo(idx, f, name);
	numberOfExceptions = r2(f);
	exceptionIndexTable = new u2[numberOfExceptions];
	for(int i=0; i<numberOfExceptions; i++) exceptionIndexTable[i] = r2(f);
}

LineNumberTableStr::LineNumberTableStr(std::ifstream& f, u2 len):
std::vector<LineNumberTableStrInfo*>(len){  
    for (u2 i = 0; i < size(); i++){
        at(i) = new LineNumberTableStrInfo();
        at(i)->startPc = r2(f);
        at(i)->lineNumber = r2(f);
    }
}

LineNumberTable::LineNumberTable(u2 idx, std::ifstream& f, std::string name){
	generalInfo(idx, f, name);
	lineNumberTableLength = r2(f);
	lnTable = new LineNumberTableStr(f, lineNumberTableLength);
}

LocalVariableTableStr::LocalVariableTableStr(std::ifstream& f, u2 len):
std::vector<LocalVariableTableStrInfo*>(len){
    for (u2 i = 0; i < size(); i++){
        at(i) = new LocalVariableTableStrInfo();
        at(i)->startPc = r2(f);
        at(i)->length = r2(f);
        at(i)->nameIndex = r2(f);
        at(i)->descriptorIndex = r2(f);
        at(i)->index = r2(f);
    }
}

LocalVariableTable::LocalVariableTable(u2 idx, std::ifstream& f, std::string name){
	generalInfo(idx, f, name);
	localVariableTableLength = r2(f);
	lvTable = new LocalVariableTableStr(f, localVariableTableLength);
}

void Attributes::getConstantValue(std::ifstream& f, ConstantPool cpt, u2 idx, std::string name){
	u4 len = r4(f);
	u2 vidx = r2(f);
	if(cpt[vidx-1].tag == CONSTANT_String){
		ConstantValue<std::string> *cv = new ConstantValue<std::string>(cpt[vidx-1].tag, idx, len, name, cpt.getUtf8Str(vidx-1));
		push_back(cv);
	}
	else if(cpt[vidx-1].tag == CONSTANT_Integer){
		ConstantValue<int> *cv = new ConstantValue<int>(cpt[vidx-1].tag, idx, len, name, cpt[vidx-1].Integer.nint);
		push_back(cv);
	}
	else if(cpt[vidx-1].tag == CONSTANT_Float){
		ConstantValue<float> *cv = new ConstantValue<float>(cpt[vidx-1].tag, idx, len, name, cpt[vidx-1].Float.nfloat);
		push_back(cv);
	}
	else if(cpt[vidx-1].tag == CONSTANT_Long){
		ConstantValue<long> *cv = new ConstantValue<long>(cpt[vidx-1].tag, idx, len, name, cpt[vidx-1].Long.nlong);
		push_back(cv);
	}
	else if(cpt[vidx-1].tag == CONSTANT_Float){
		ConstantValue<double> *cv = new ConstantValue<double>(cpt[vidx-1].tag, idx, len, name, cpt[vidx-1].Double.ndouble);
		push_back(cv);
	}	
}

Attributes::Attributes(std::ifstream& f, u2 attributesCount, ConstantPool cpt){
	for(int i=0; i<attributesCount; i++){
		u2 idx = r2(f);
		std::string name = cpt.Bytes2Str(cpt[idx - 1]);
		if(!name.compare("SourceFile")){
			SourceFile *sf = new SourceFile(idx, f, name);
			push_back(sf);
		}
		else if(!name.compare("InnerClasses")){
			InnerClasses *ic = new InnerClasses(idx, f, name);
			push_back(ic);
		}
		else if(!name.compare("ConstantValue")){
			getConstantValue(f, cpt, idx, name);
		}
		else if(!name.compare("Code")){
			Code *c = new Code(idx, f, cpt, name);
			push_back(c);
		}
		else if(!name.compare("Exceptions")){
			Exceptions *ex = new Exceptions(idx, f, name);
			push_back(ex);
		}
		else if(!name.compare("Synthetic") || !name.compare("Deprecated")){
			AttributeInfo *att = new AttributeInfo(idx, f, name);
			push_back(att);
		}
		else if(!name.compare("LineNumberTable")){
			LineNumberTable *lnt = new LineNumberTable(idx, f, name);
			push_back(lnt);
		}
		else if(!name.compare("LocalVariableTable")){
			LocalVariableTable *lvt = new LocalVariableTable(idx, f, name);
			push_back(lvt);
		}	
		else
			std::cout << "Atributo não implementado!" << std::endl;
	}
}

// DISPLAY_______________________________________________________________________________
void LineNumberTable::print(std::ostream& out){
	for(auto lntinfo : *lnTable){
		out << ".......................: " << std::endl;
		out << "Start Pc...............: " << lntinfo->startPc << std::endl;
		out << "End Pc.................: " << lntinfo->lineNumber << std::endl;
	}
}

void LocalVariableTable::print(std::ostream& out, ConstantPool cpt){
	for(auto lvtinfo : *lvTable){
		out << ".......................: " << std::endl;
		out << "Start Pc...............: " << lvtinfo->startPc << std::endl;
		out << "length.................: " << lvtinfo->length << std::endl;
		out << "Name...................: " << cpt.getUtf8Str(lvtinfo->nameIndex) << std::endl;
		out << "Descriptor.............: " << cpt.getUtf8Str(lvtinfo->descriptorIndex) << std::endl;
		
	}
}

void ExceptionTable::print(std::ostream& out){
	if(size()){
		for(auto exc : *this){
			out << "(Exception Table)......: " << std::endl;
			out << "Start Pc...............: " << exc->startPc << std::endl;
			out << "End Pc.................: " << exc->endPc << std::endl;	
			out << "Handler Pc.............: " << exc->handlerPc << std::endl;
			out << "Catch Type.............: " << exc->catchType << std::endl;
		}
	}
}

void Code::print(std::ostream& out, ConstantPool cpt){
	out << std::noshowbase;
	out << "Maximum depth..........: " << std::dec << maxStack << std::endl;
	out << "Nos of local variables.: " << std::dec << maxLocals << std::endl;
	out << "Code...................: 0x";
	for(u4 i=0; i<codeLength; i++) out << std::hex << (int)code[i];
	exceptionTable->print(out);
	out << std::endl;
	if(attributesCount){
		out << "Atributos opcionais associados:" << std::endl;
		attributes->print(out, cpt);
	}
	out << std::showbase;
}

void Exceptions::print(std::ostream& out, ConstantPool cpt){
	out << "Number Of Exceptions...: " << std::dec << numberOfExceptions << std::endl;
	for(u2 i=0; i<numberOfExceptions; i++) 
		out << "Class whose method will throw: " << cpt.getUtf8Class(exceptionIndexTable[i]-1);
	out << std::endl;
}

template<typename T>
void ConstantValue<T>::print(std::ostream& out){
	out << "Value..................: cp[" << std::dec << constantvalueIndex-1;
	out << "] (";    
	if(tagValue == CONSTANT_String) out << "String) = " << value << std::endl;
	if(tagValue == CONSTANT_Integer) out << "Integer) = " << std::dec << value << std::endl;
	if(tagValue == CONSTANT_Float) out << "Float) = " << value << std::endl;
	if(tagValue == CONSTANT_Long) out << "Long) = " << std::dec << value << std::endl;
	if(tagValue == CONSTANT_Double) out << "Double) = " << value << std::endl;
}

void InnerClasses::print(std::ostream& out, ConstantPool cpt){
	out << "Number of classes......: " << numberOfClasses << std::endl;
	out << "Classes................: ";
	for(auto c : *classes){
		out << "Inner Class........: cp[" << std::dec << c->innerClassInfoIndex-1;
		out << "] = " << cpt.getUtf8Class(c->innerClassInfoIndex-1) << std::endl;
		if(c->innerNameIndex){
			out << "Outer Class........: cp[" << std::dec << c->outerClassInfoIndex-1;
			out << "] = " << cpt.Bytes2Str(cpt[c->innerNameIndex-1]) << std::endl;
		}
		else  out << "Original Name: " << std::dec << c->innerNameIndex;
		if(c->outerClassInfoIndex){
			out << "Outer Class........: cp[" << std::dec << c->outerClassInfoIndex-1;
			out << "] = " << cpt.getUtf8Class(c->outerClassInfoIndex-1) << std::endl;
		}
		else  out << "OuterClassInfoIndex: " << std::dec << c->outerClassInfoIndex;
		c->acessFlags.print(out);
	}
}

void SourceFile::print(std::ostream& out, ConstantPool cpt){
	out << "Source File............: cp[" << std::dec << sourcefileIndex-1;
	out << "] = " << cpt.getUtf8Str(sourcefileIndex-1) << std::endl;
}

void Attributes::print(std::ostream& out, ConstantPool cpt){
	for(auto attribute : *this){
	   	out << ".......................:" << std::endl;
	   	out << "(Attribute)............:" << std::endl;
	   	out << "Attribute Name.........: cp[" << std::dec << attribute->attributeNameIndex-1;
		out << "] = " << attribute->name << std::endl;
		out << "Attribute Length.......: " << (int)attribute->attributeLength << std::endl;	
	    attribute->print(out, cpt);
	    attribute->print(out);
	}
}