#include "Display.h"
#include "ClassFile.h"


std::map<int, std::string> versionsMap{ 
	{45, "1.1"}, {46, "1.2"}, {47, "1.3"}, {48, "1.4"}, {49, "1.5"},
	{50, "1.6"}, {51, "1.7"}, {52, "1.8"}, {53, "1.9"}, {54, "1.10"}, 
	{55, "1.11"}, {56, "1.12"}, {57, "1.13"}, {58, "1.14"} };

	
void printClassFile(ClassFile *classFile){
	std::cout << std::hex << classFile->magic << std::endl;
	std::cout << std::hex << classFile->minorVersion << std::endl;
	std::cout << std::hex << classFile->majorVersion << std::endl;
	std::cout << std::hex << classFile->constantPoolCount << std::endl;
	//classFile->constantPool.print();
	classFile->fields.printFields();
	classFile->methods.print(classFile->constantPool);
}
