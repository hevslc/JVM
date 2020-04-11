#include "FieldInfo.h"
//#include <math.h>

Fields::Fields(std::ifstream& f, u2 fieldsCount ,ConstantPoolT constantPool):
std::vector<FieldInfo*>(readFieldsCount(fieldsCount)){ 
	if(fieldsCount){
		for(u2 i = 0; i < size(); i++){
			at(i)= new FieldInfo();
			at(i)->accessFlags = r2(f);
			at(i)->nameIndex = r2(f);
			at(i)->descriptorIndex = r2(f);
			at(i)->attributesCount = r2(f);		
			at(i)->attributes = new Attributes(f, at(i)->attributesCount, constantPool);
		}
	}
}


void Fields::printFields(){
	std::cout << "__________________Fields__________________" << std::endl;
	for(u2 i = 0; i < size(); i++){
		std::cout << "accessFlags....: "   <<at(i)->accessFlags << std::endl;
		if(at(i)->accessFlags == ACC_PUBLIC)
			std::cout << "acessFlags.....: ACC_PUBLIC"  << std::endl;
		else if(at(i)->accessFlags == ACC_PRIVATE)
			std::cout << "acessFlags.....: ACC_PRIVATE"  << std::endl;
		else if(at(i)->accessFlags ==ACC_PROTECTED)
			std::cout << "acessFlags.....: ACC_PROTECTED"  << std::endl;
		else if(at(i)->accessFlags ==ACC_STATIC)
			std::cout << "acessFlags.....: ACC_STATIC"  << std::endl;
		else if(at(i)->accessFlags ==ACC_FINAL)
			std::cout << "acessFlags.....: ACC_FINAL"  << std::endl;
		else if(at(i)->accessFlags ==ACC_VOLATILE)
			std::cout << "acessFlags.....: ACC_VOLATILE"  << std::endl;
		else if(at(i)->accessFlags ==ACC_TRANSIENT)
			std::cout << "acessFlags.....: ACC_TRANSIENT"  << std::endl; 
		else if(at(i)->accessFlags ==ACC_SYNTHETIC)
			std::cout << "acessFlags.....: ACC_SYNTHETIC"  << std::endl;
		else if(at(i)->accessFlags ==ACC_ENUM)
			std::cout << "acessFlags.....: ACC_ENUM"  << std::endl;
		
		std::cout << "nameIndex......: "  << at(i)->nameIndex << std::endl;
		std::cout << "descriptorIndex: "  << at(i)->descriptorIndex << std::endl;
		std::cout << "attributesCount: "  << at(i)->attributesCount << std::endl;
		//std::cout << "attributes.....: "  << at(i)->attributes << std::endl;
		std::cout << "................................................."<< std::endl;
	}
}

u2 Fields::readFieldsCount(u2 fieldsCount) {
    return fieldsCount;
}