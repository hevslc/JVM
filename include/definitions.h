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

class ConstantClass : Cpinfo{
	u2 nameIndex;
};

class ConstantFieldref : Cpinfo{
	u2 classIndex;
	u2 nameTypeIndex;
};

class ConstantMethodref : Cpinfo{
	u2 classIndex;
	u2 nameTypeIndex;
};

class ConstantInterfaceMethodref : Cpinfo{
	u2 classIndex;
	u2 nameTypeIndex;
};

class ConstantString : Cpinfo{
	u2 stringIndex;
};

class ConstantInteger : Cpinfo{
	u4 bytes;
};

class ConstantFloat : Cpinfo{
	u4 bytes;
};

class ConstantLong : Cpinfo{
	u4 highBytes;
	u4 lowBytes;
};

class ConstantDouble : Cpinfo{
	u4 highBytes;
	u4 lowBytes;
};

class ConstantNameAndType : Cpinfo{
	u2 nameIndex;
	u2 descriptorIndex;
};

class ConstantUtf8 : Cpinfo{
	u2 lenght;
	u1 bytes;
};

class ConstantMethodHandle : Cpinfo{
	u1 referenceKind;
	u2 referenceIndex;
};

/*class ConstantInterfaceMethodref : Cpinfo{
	u1 referenceKind;
	u2 referenceIndex;
};
*/

class ConstantMethodType : Cpinfo{
	u2 descriptorIndex;
};

class ConstantInvokeDynamic : Cpinfo{
	u2 bootstrapMethodAttrIndex;
	u2 nameTypeIndex;
};



#endif
