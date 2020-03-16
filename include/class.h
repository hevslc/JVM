#ifndef CLASS_H
#define CLASS_H

#include "definitions.h"

class ClassFile{
public:
	u4				magic;
	u2				minor_version;
	u2				major_version;
	u2				constant_pool_count;
	//cp_info			constant_pool;
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
	ClassFile();
};



#endif