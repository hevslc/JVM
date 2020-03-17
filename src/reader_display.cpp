#include "reader_display.h"


u1 ClassFile::r1(std::ifstream& f){
	u1 b;
	f.read((char *)&b, sizeof(u1));
	return b;
}

u2 ClassFile::r2(std::ifstream& f){
	u2 b = (u2)r1(f) << 8;
	b = b | (u2)r1(f);
	return b;
}

u4 ClassFile::r4(std::ifstream& f){
	u4 b = (u4)r1(f) << 24;
	b = b | (u4)r1(f) << 16;
	b = b | (u4)r1(f) << 8;
	b = b | (u4)r1(f);
	return b;	
}

void ClassFile::reading(std::ifstream& f){
	this->magic = r4(f);					//reading magic
	this->minorVersion = r2(f);				//reading minor version
	this->majorVersion = r2(f);				//reading major version
	this->constantPoolCount = r2(f);		//reading constant pool count
}

void ClassFile::rconstantPoolt(std::ifstream& f){
	Cpinfo *cpinfo = new Cpinfo[this->constantPoolCount-1];
	for(int i=0; i<this->constantPoolCount-1; i++){
		cpinfo[i].tag = r1(f);
		switch(cpinfo[i].tag){
			case CONSTANT_Class:
				cpinfo[i].Class.nameIndex = r2(f);
				break;
			case CONSTANT_Fieldref:
				cpinfo[i].Fieldref.classIndex = r2(f);
				cpinfo[i].Fieldref.nameTypeIndex = r2(f);
				break;
			case CONSTANT_Methodref:
				cpinfo[i].Methodref.classIndex = r2(f);
				cpinfo[i].Methodref.nameTypeIndex = r2(f);
				break;
			case CONSTANT_InterfaceMethodref:
				cpinfo[i].InterfaceMethodref.classIndex = r2(f);
				cpinfo[i].InterfaceMethodref.nameTypeIndex = r2(f);
				break;
			case CONSTANT_String:
				cpinfo[i].String.stringIndex = r2(f);
				break;
			case CONSTANT_Integer:
				cpinfo[i].Integer.bytes = r4(f);
				break;
			case CONSTANT_Float:
				cpinfo[i].Float.bytes = r4(f);
				break;
			case CONSTANT_Long:
				cpinfo[i].Long.highBytes = r4(f);
				cpinfo[i].Long.lowBytes = r4(f);
				break;
			case CONSTANT_Double:
				cpinfo[i].Double.highBytes = r4(f);
				cpinfo[i].Double.lowBytes = r4(f);
				break;
			case CONSTANT_NameAndType:
				cpinfo[i].NameAndType.nameIndex = r2(f);
				cpinfo[i].NameAndType.descriptorIndex = r2(f);
				break;
			case CONSTANT_Utf8:
				cpinfo[i].Utf8.lenght = r2(f);
				cpinfo[i].Utf8.bytes = new u1[cpinfo[i].Utf8.lenght];
				for(int i=0; i<cpinfo[i].Utf8.lenght; i++) cpinfo[i].Utf8.bytes[i] = r1(f);
				break;
			default:
				break;
		}
	}
	this->constantPool = cpinfo;
}