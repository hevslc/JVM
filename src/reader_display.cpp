#include "reader_display.h"


u1 r1(std::ifstream& f){
	u1 b;
	f.read((char *)&b, sizeof(u1));
	return b;
}

u2 r2(std::ifstream& f){
	u2 b = (u2)r1(f) << 8;
	b = b | (u2)r1(f);
	return b;
}

u4 r4(std::ifstream& f){
	u4 b = (u4)r1(f) << 24;
	b = b | (u4)r1(f) << 16;
	b = b | (u4)r1(f) << 8;
	b = b | (u4)r1(f);
	return b;
}

void reading(ClassFile *classFile, std::ifstream& f){
	classFile->magic = r4(f);					//reading magic
	classFile->minor_version = r2(f);			//reading minor version
	classFile->major_version = r2(f);			//reading major version
	classFile->constant_pool_count = r2(f);		//reading constant pool count
}