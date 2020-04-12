#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <sys/stat.h>
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


enum enumAcessFlags : u2 { ACC_PUBLIC=0x0001,       ACC_PRIVATE=0x0002,    ACC_PROTECTED=0x0004, 
						   ACC_STATIC=0x0008,       ACC_FINAL=0x0010,      ACC_SUPER=0x0020, 
						   ACC_SYNCHRONIZED=0x0020, ACC_VOLATILE=0x0040,   ACC_BRIDGE=0x0040, 
						   ACC_TRANSIENT=0x0080,    ACC_VARARGS=0x0080,    ACC_NATIVE=0x0100, 
						   ACC_INTERFACE=0x0200,    ACC_ABSTRACT=0x0400,   ACC_STRICT=0x0800,
						   ACC_SYNTHETIC=0x1000,    ACC_ANNOTATION=0x2000, ACC_ENUM=0x4000};

enum ModePrint : u1 {infile, interminal};


class Version{
public:
	std::string v;
	Version() {}
	void put(u2 major){ v = versionsMap[major]; }
	std::string get() {return v; }

	std::map<u2, std::string> versionsMap{ 
	{45, "1.1"}, {46, "1.2"}, {47, "1.3"}, {48, "1.4"}, {49, "1.5"},
	{50, "1.6"}, {51, "1.7"}, {52, "1.8"}, {53, "1.9"}, {54, "1.10"}, 
	{55, "1.11"}, {56, "1.12"}, {57, "1.13"}, {58, "1.14"} };
};




class AcessFlags{
public:
	AcessFlags() {}

	void set(u2 mask){
		for(auto p=acessFlagsMap.begin(); p!=acessFlagsMap.end(); ++p)
			p->second = ((p->first & mask)==p->first);
	}
	
	void print(std::ostream& out){
		out << "\nAcess Flags......: ";
		int i=0;
		for(auto const& p : acessFlagsMap){
			if(p.second) out << AcessFlagsStr[i] << ", ";
			i++;
		}
		out << '\n';
	}

	std::map<enumAcessFlags, bool> acessFlagsMap{{ACC_PUBLIC, false}, {ACC_FINAL, false},
		{ACC_SUPER, false}, {ACC_INTERFACE, false}, {ACC_ABSTRACT, false},
		{ACC_SYNTHETIC, false}, {ACC_ANNOTATION, false}, {ACC_ENUM, false}};

private:
	std::string AcessFlagsStr[18] = {"ACC_PUBLIC", "ACC_FINAL", "ACC_SUPER",  
	"ACC_INTERFACE", "ACC_ABSTRACT", "ACC_SYNTHETIC",  "ACC_ANNOTATION", "ACC_ENUM"};
};

#endif