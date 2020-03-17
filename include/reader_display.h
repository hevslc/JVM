#ifndef READER_H
#define READER_H

#include "definitions.h"



class ClassFile{
public:
	u4				magic;
	u2				minorVersion;
	u2				majorVersion;
	u2				constantPoolCount;
	Cpinfo			*constantPool;
	//u2				acess_flags;
	//u2				this_class;
	//u2				super_class;
	//u2				interfaces_count;
	//u2				interfaces;
	//u2				fiels_count;
	//field_info		field;
	//u2				methods_count;
	//method_info		methods;
	//u2				attributes_count;
	//attribute_info	attribute;


	u1 r1(std::ifstream& f);
	u2 r2(std::ifstream& f);
	u4 r4(std::ifstream& f);
	void reading(std::ifstream& f);

private:
	void rconstantPoolt(std::ifstream& f);



};


#endif