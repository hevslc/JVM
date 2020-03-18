#include "display.h"


// PARA TESTE
void dconstantPoolt(ClassFile *classFile){
	std::cout << std::hex << classFile->magic << std::endl;
	std::cout << std::hex << classFile->minorVersion << std::endl;
	std::cout << std::hex << classFile->majorVersion << std::endl;
	std::cout << std::hex << classFile->constantPoolCount << std::endl;
	std::cout << "__________________constantPool__________________" << std::endl;
	for(int i=0; i<classFile->constantPoolCount; i++){
		std::cout << "tag: "   << (int)classFile->constantPool[i].tag << std::endl;
		switch(classFile->constantPool[i].tag){
			case CONSTANT_Class:
				std::cout << "nameIndex: "  << classFile->constantPool[i].Class.nameIndex << std::endl;
				break;
			case CONSTANT_Fieldref:
			case CONSTANT_Methodref:
			case CONSTANT_InterfaceMethodref:
				std::cout << "classIndex: "  << classFile->constantPool[i].FieldMethInter.classIndex << std::endl;
				std::cout << "nameTypeIndex: "  << classFile->constantPool[i].FieldMethInter.nameTypeIndex << std::endl;
				break;
			case CONSTANT_String:
				std::cout << "stringIndex: "  << classFile->constantPool[i].String.stringIndex << std::endl;
				break;
			case CONSTANT_Integer:
			case CONSTANT_Float:
				std::cout << "bytes: "  << classFile->constantPool[i].IntegerFloat.bytes << std::endl;
				break;
			case CONSTANT_Long:
			case CONSTANT_Double:
				std::cout << "highBytes: "  << classFile->constantPool[i].LongDouble.highBytes << std::endl;
				std::cout << "lowBytes: "  << classFile->constantPool[i].LongDouble.lowBytes << std::endl;
				break;
			case CONSTANT_NameAndType:
				std::cout << "nameIndex: "  << classFile->constantPool[i].NameAndType.nameIndex << std::endl;
				std::cout << "descriptorIndex: "  << classFile->constantPool[i].NameAndType.descriptorIndex << std::endl;
				break;
			case CONSTANT_Utf8:
				std::cout << "lenght: "  << classFile->constantPool[i].Utf8.lenght << std::endl;
				for(int j=0; j<classFile->constantPool[i].Utf8.lenght; j++) 
					std::cout << classFile->constantPool[i].Utf8.bytes[j];
				std::cout << std::endl;
				break;
			default:
				break;
		}
	}
}