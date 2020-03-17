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

class Cpinfo{
	u1 tag;
};



#endif
