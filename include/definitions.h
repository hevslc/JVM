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
public:
	u1 tag;
	union{					
		struct{
			u2 nameIndex;
		}Class;

		struct{
			u2 classIndex;
			u2 nameTypeIndex;
		}Fieldref;

		struct{
			u2 classIndex;
			u2 nameTypeIndex;
		}Methodref;

		struct{
			u2 classIndex;
			u2 nameTypeIndex;
		}InterfaceMethodref;

		struct{
			u2 stringIndex;
		}String;

		struct{
			u4 bytes;
		}Integer;

		struct{
			u4 bytes;
		}Float;

		struct{
			u4 highBytes;
			u4 lowBytes;
		}Long;

		struct{
			u4 highBytes;
			u4 lowBytes;
		}Double;

		struct{
			u2 nameIndex;
			u2 descriptorIndex;
		}NameAndType;

		struct{
			u2 lenght;
			u1 *bytes;
		}Utf8;

		struct{
			u1 referenceKind;
			u2 referenceIndex;
		}MethodHandle;
	};
};





#endif
