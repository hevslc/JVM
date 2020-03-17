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
	this->magic = r4(f);						//reading magic
	this->minorVersion = r2(f);				//reading minor version
	this->majorVersion = r2(f);				//reading major version
	this->constantPoolCount = r2(f);		    //reading constant pool count
}
