#include "AttributeInfo.h"


std::string Attributes::readName(u2 lenght, u1 *bytes){
	std::string name;
	for(int i=0; i<lenght; i++) name.push_back(char(bytes[i]));
	return name;
}



Attributes::Attributes(std::ifstream& f, u2 attributesCount, ConstantPoolT constantPool){
	for(int i=0; i<attributesCount; i++){
		u2 idx = r2(f);
		Cpinfo cpinfo = constantPool[idx];
		std::string name = readName(cpinfo.Utf8.lenght, cpinfo.Utf8.bytes);
		std::cout << name << std::endl;
		if(!name.compare("SourceFile")){
			SourceFile *sf = new SourceFile(idx, r4(f));
			sf->sourcefileIndex = r2(f);
			push_back(sf);
		}
		else if(!name.compare("InnerClasses")){

		}
		else if(!name.compare("ConstantValue")){

		}
		else if(!name.compare("Code")){

		}
		else if(!name.compare("Exceptions")){

		}
		else if(!name.compare("Synthetic") || !name.compare("Deprecated")){

		}
		else if(!name.compare("LineNumberTable")){

		}
		else if(!name.compare("LocalVariableTable")){

		}		
	}
}