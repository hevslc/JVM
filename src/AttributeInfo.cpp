#include "AttributeInfo.h"



std::string Attributes::readName(Cpinfo cpi){
	std::string name;
	for(int i=0; i<cpi.Utf8.lenght; i++) name.push_back(char(cpi.Utf8.bytes[i]));
	return name;
}

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
    if(len){    
        for (u2 i = 0; i < size(); i++){
            at(i) = new ClassesInfo();
            at(i)->innerClassInfoIndex = r2(f);
            at(i)->outerClassInfoIndex = r2(f);
            at(i)->innerNameIndex = r2(f);
            at(i)->innerClassAccessFlags = r2(f);
        }
    }
}

InnerClasses::InnerClasses(u2 idx, std::ifstream& f, std::string name){
	generalInfo(idx, f, name);
	numberOfClasses = r2(f);
	classes = new Classes(f, numberOfClasses);
}

ConstantValue::ConstantValue(u2 idx, std::ifstream& f, std::string name){
	generalInfo(idx, f, name);
	constantvalueIndex = r2(f);
}

ExceptionTable::ExceptionTable(std::ifstream& f, u2 len):
std::vector<ExceptionTableInfo*>(len){
    if(len){    
        for (u2 i = 0; i < size(); i++){
            at(i) = new ExceptionTableInfo();
            at(i)->startPc = r2(f);
            at(i)->endPc = r2(f);
            at(i)->handlerPc = r2(f);
            at(i)->catchType = r2(f);
        }
    }
}

Code::Code(u2 idx, std::ifstream& f, ConstantPoolT constantPool, std::string name){
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
    if(len){    
        for (u2 i = 0; i < size(); i++){
            at(i) = new LineNumberTableStrInfo();
            at(i)->startPc = r2(f);
            at(i)->lineNumber = r2(f);
        }
    }
}

LineNumberTable::LineNumberTable(u2 idx, std::ifstream& f, std::string name){
	generalInfo(idx, f, name);
	lineNumberTableLength = r2(f);
	lnTable = new LineNumberTableStr(f, lineNumberTableLength);
}

LocalVariableTableStr::LocalVariableTableStr(std::ifstream& f, u2 len):
std::vector<LocalVariableTableStrInfo*>(len){
    if(len){    
        for (u2 i = 0; i < size(); i++){
            at(i) = new LocalVariableTableStrInfo();
            at(i)->startPc = r2(f);
            at(i)->length = r2(f);
            at(i)->nameIndex = r2(f);
            at(i)->descriptorIndex = r2(f);
            at(i)->index = r2(f);
        }
    }
}

LocalVariableTable::LocalVariableTable(u2 idx, std::ifstream& f, std::string name){
	generalInfo(idx, f, name);
	localVariableTableLength = r2(f);
	lvTable = new LocalVariableTableStr(f, localVariableTableLength);
}

Attributes::Attributes(std::ifstream& f, u2 attributesCount, ConstantPoolT constantPool){
	if(attributesCount){
		for(int i=0; i<attributesCount; i++){
			u2 idx = r2(f);
			std::string name = readName(constantPool[idx - 1]);
			if(!name.compare("SourceFile")){
				SourceFile *sf = new SourceFile(idx, f, name);
				push_back(sf);
			}
			else if(!name.compare("InnerClasses")){
				InnerClasses *ic = new InnerClasses(idx, f, name);
				push_back(ic);
			}
			else if(!name.compare("ConstantValue")){
				ConstantValue *cv = new ConstantValue(idx, f, name);
				push_back(cv);
			}
			else if(!name.compare("Code")){
				Code *c = new Code(idx, f, constantPool, name);
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
}

void Attributes::print(ConstantPoolT cpt){
	(void)cpt;
}
