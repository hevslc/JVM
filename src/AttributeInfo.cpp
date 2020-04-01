#include "AttributeInfo.h"



std::string Attributes::readName(u2 lenght, u1 *bytes){
	std::string name;
	for(int i=0; i<lenght; i++) name.push_back(char(bytes[i]));
	return name;
}

void AttributeInfo::generalInfo(u2 idx, std::ifstream& f){ 
	attributeNameIndex = idx;
	attributeLength = r4(f); 
}

SourceFile::SourceFile(u2 idx, std::ifstream& f){
	generalInfo(idx, f);
	sourcefileIndex = r2(f);
}

InnerClasses::InnerClasses(u2 idx, std::ifstream& f){
	generalInfo(idx, f);
	numberOfClasses = r2(f);
	//Classes *cl = (Classes*) malloc(numberOfClasses*sizeof(Classes));
	/*for(int i=0; i<numberOfClasses; i++){
		classes[i].innerClassInfoIndex = r2(f);
		classes[i].outerClassInfoIndex = r2(f);
		classes[i].innerNameIndex = r2(f);
		classes[i].innerClassAccessFlags = r2(f);
	}*/
}

ConstantValue::ConstantValue(u2 idx, std::ifstream& f){
	generalInfo(idx, f);
	constantvalueIndex = r2(f);
}

Code::Code(u2 idx, std::ifstream& f, ConstantPoolT constantPool){
	generalInfo(idx, f);
	maxStack = r2(f);
	maxLocals = r2(f);
	codeLength = r4(f);
	code = new u1[codeLength];
	for(u2 i=0; i<codeLength; i++)  code[i] = r1(f);
	exceptionTableLength = r2(f);
	// ler table
	attributesCount = r2(f);
	Attributes *attributes = new Attributes(f, attributesCount, constantPool);
	this->attributes = *attributes;
}

Exceptions::Exceptions(u2 idx, std::ifstream& f){
	generalInfo(idx, f);
	numberOfExceptions = r2(f);
	exceptionIndexTable = new u2[numberOfExceptions];
	for(int i=0; i<numberOfExceptions; i++) exceptionIndexTable[i] = r2(f);
}

LineNumberTable::LineNumberTable(u2 idx, std::ifstream& f){
	generalInfo(idx, f);
	lineNumberTableLength = r2(f);
	// ler table
}

LocalVariableTable::LocalVariableTable(u2 idx, std::ifstream& f){
	generalInfo(idx, f);
	localVariableTableLength = r2(f);
	// ler table
}

Attributes::Attributes(std::ifstream& f, u2 attributesCount, ConstantPoolT constantPool){
	for(int i=0; i<attributesCount; i++){
		u2 idx = r2(f);
		Cpinfo cpinfo = constantPool[idx];
		std::string name = readName(cpinfo.Utf8.lenght, cpinfo.Utf8.bytes);
		std::cout << "Attribute name: " << name << std::endl;
		if(!name.compare("SourceFile")){
			SourceFile *sf = new SourceFile(idx, f);
			push_back(sf);
		}
		else if(!name.compare("InnerClasses")){
			InnerClasses *ic = new InnerClasses(idx, f);
			push_back(ic);
		}
		else if(!name.compare("ConstantValue")){
			ConstantValue *cv = new ConstantValue(idx, f);
			push_back(cv);
		}
		else if(!name.compare("Code")){
			Code *c = new Code(idx, f, constantPool);
			push_back(c);
		}
		else if(!name.compare("Exceptions")){
			Exceptions *ex = new Exceptions(idx, f);
			push_back(ex);
		}
		else if(!name.compare("Synthetic") || !name.compare("Deprecated")){
			AttributeInfo *att = new AttributeInfo(idx, f);
			push_back(att);
		}
		else if(!name.compare("LineNumberTable")){
			LineNumberTable *lnt = new LineNumberTable(idx, f);
			push_back(lnt);
		}
		else if(!name.compare("LocalVariableTable")){
			LocalVariableTable *lvt = new LocalVariableTable(idx, f);
			push_back(lvt);

		}		
	}
}