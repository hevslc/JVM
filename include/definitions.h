#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <fstream>
#include <iostream>


typedef unsigned char 	u1;
typedef unsigned short 	u2;
typedef unsigned int 	u4;

#define CONSTANT_Class 				7
#define CONSTANT_Fieldref 			9
#define CONSTANT_Methodref 			10
#define CONSTANT_InterfaceMethodref 11
#define CONSTANT_String 			8
#define CONSTANT_Integer 			3
#define CONSTANT_Float 				4
#define CONSTANT_Long 				5
#define CONSTANT_Double 			6
#define CONSTANT_NameAndType 		12
#define CONSTANT_Utf8 				1

class Cp_info{
	u1 tag;
	u1 info[];
};


class ClassFile{
public:
	u4				magic;
	u2				minor_version;
	u2				major_version;
	u2				constant_pool_count;
	Cp_info			constant_pool;
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
};




#endif
