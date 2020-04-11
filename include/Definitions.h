#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <fstream>
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <map>
#include <limits>
#include <math.h>       /* exp */


typedef uint8_t 	u1;					/*!< Tipo de dado (8 bits)  */
typedef uint16_t	u2;					/*!< Tipo de dado (16 bits) */
typedef uint32_t 	u4;	

//! Método reading
/*!
	Cada item na tabela constant_pool deve começar com uma tag de 1 byte, 
	indicando o tipo de entrada cp_info. Tags:
*/ 
	

enum constantType : u1 {CONSTANT_Utf8=1, CONSTANT_Integer=3, CONSTANT_Float=4, CONSTANT_Long=5, 
				  CONSTANT_Double=6, CONSTANT_Class=7, CONSTANT_String=8, CONSTANT_Fieldref=9, 
				  CONSTANT_Methodref=10,CONSTANT_InterfaceMethodref=11,CONSTANT_NameAndType=12};

u1 r1(std::ifstream& f);			/*!< Lê 1 byte do arquivo */
u2 r2(std::ifstream& f);			/*!< Lê 2 byte do arquivo */
u4 r4(std::ifstream& f);			/*!< Lê 4 byte do arquivo */

extern std::map<int, std::string> versionsMap;

enum enumAcessFlags : u2 { ACC_PUBLIC=0x0001,       ACC_PRIVATE=0x0002,    ACC_PROTECTED=0x0004, 
						   ACC_STATIC=0x0008,       ACC_FINAL=0x0010,      ACC_SUPER=0x0020, 
						   ACC_SYNCHRONIZED=0x0020, ACC_VOLATILE=0x0040,   ACC_BRIDGE=0x0040, 
						   ACC_TRANSIENT=0x0080,    ACC_VARARGS=0x0080,    ACC_NATIVE=0x0100, 
						   ACC_INTERFACE=0x0200,    ACC_ABSTRACT=0x0400,   ACC_STRICT=0x0800,
						   ACC_SYNTHETIC=0x1000,    ACC_ANNOTATION=0x2000, ACC_ENUM=0x4000};


#endif