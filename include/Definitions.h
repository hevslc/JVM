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
#include <stack>
#include <array>


typedef uint8_t 	u1;	/*!< Tipo de dado (1 byte)  */
typedef uint16_t	u2;	/*!< Tipo de dado (4 bytes) */
typedef uint32_t 	u4;	/*!< Tipo de dado (4 bytes) */
typedef uint64_t 	u8;	/*!< Tipo de dado (8 bytes) */

/*!
   \brief Flags de acesso para um CpInfo.
 */
enum constantType : u1
{
	CONSTANT_Utf8 = 1,
	CONSTANT_Integer = 3,
	CONSTANT_Float = 4,
	CONSTANT_Long = 5,
	CONSTANT_Double = 6,
	CONSTANT_Class = 7,
	CONSTANT_String = 8,
	CONSTANT_Fieldref = 9,
	CONSTANT_Methodref = 10,
	CONSTANT_InterfaceMethodref = 11,
	CONSTANT_NameAndType = 12
};

u1 r1(std::ifstream& f); /*!< Lê 1 byte do arquivo */
u2 r2(std::ifstream& f); /*!< Lê 2 byte do arquivo */
u4 r4(std::ifstream& f); /*!< Lê 4 byte do arquivo */

/*!
   \brief Para indicar o modo de impressão.
 */
enum ModePrint : u1
{
	infile,	   /*!< Impressão em arquivo */
	interminal /*!< Impressão em terminal */
};

/*!
   \brief Versão Java do arquivo .class.
   Delega para si o processamento das versões Java.
 */
class Version {
public:
	std::string v; /*!< String que indica a versão */

	/*!
	   \brief Constrói um novo objeto Version.
	 */
	Version() {}

	/*!
	   \brief Define a versão.
	   Faz isso a partir do valor lido no arquivo .class.
	   \param major Versão major lida no arquivo.
	 */
	void put(u2 major) { v = versionsMap[major];}

	/*!
	   \return Versão do arquivo.
	 */
	std::string get() { return v; }

	/*!
	   \brief Mapa para tradução de versões.
	 */
	std::map<u2, std::string> versionsMap { 
	{45, "1.1"},  {46, "1.2"},  {47, "1.3"},  {48, "1.4"}, {49, "1.5"},
	{50, "1.6"},  {51, "1.7"},  {52, "1.8"},  {53, "1.9"}, {54, "1.10"}, 
	{55, "1.11"}, {56, "1.12"}, {57, "1.13"}, {58, "1.14"} };
};

/*!
   \brief Flags de acesso.
   Utilizadas em várias partes do código.
 */
enum enumAcessFlags : u2 { ACC_PUBLIC = 0x0001,       ACC_PRIVATE = 0x0002,    ACC_PROTECTED = 0x0004, 
						   ACC_STATIC = 0x0008,       ACC_FINAL = 0x0010,      ACC_SUPER = 0x0020, 
						   ACC_SYNCHRONIZED = 0x0020, ACC_VOLATILE = 0x0040,   ACC_BRIDGE = 0x0040, 
						   ACC_TRANSIENT = 0x0080,    ACC_VARARGS = 0x0080,    ACC_NATIVE = 0x0100, 
						   ACC_INTERFACE = 0x0200,    ACC_ABSTRACT = 0x0400,   ACC_STRICT = 0x0800,
						   ACC_SYNTHETIC = 0x1000,    ACC_ANNOTATION = 0x2000, ACC_ENUM = 0x4000 };

/*!
   \brief Flags de acesso
   Delega para si o processamento das flags de acesso.
 */
class AcessFlags {
public:
	/*!
	   \brief Constrói um novo objeto AcessFlags
	 */
	AcessFlags() {}

	/*!
	   \brief Define as flags ativas para uma classe/método/atributo.
	   
	   \param mask Máscara.
	 */
	void set(u2 mask){
		for(auto p=acessFlagsMap.begin(); p!=acessFlagsMap.end(); ++p)
			p->second = ((p->first & mask)==p->first);
	}
	
	/*!
	   \brief Imprime as flags de acesso.
	   
	   \param out Stream para impressão das flags.
	 */
	void print(std::ostream& out){
		out << std::endl << "Acess Flags............: ";
		int i=0;
		for(auto const& p : acessFlagsMap){
			if(p.second) out << AcessFlagsStr[i] << ", ";
			i++;
		}
		out << std::endl;
	}

	/*!
	   \brief Indica as flags ativas.
	 */
	std::map<enumAcessFlags, bool> acessFlagsMap {
		{ACC_PUBLIC,false},       {ACC_PRIVATE,false},    {ACC_PROTECTED,false}, 
		{ACC_STATIC,false},       {ACC_FINAL,false},      {ACC_SUPER,false}, 
		{ACC_SYNCHRONIZED,false}, {ACC_VOLATILE,false},   {ACC_BRIDGE,false}, 
		{ACC_TRANSIENT,false},    {ACC_VARARGS,false},    {ACC_NATIVE,false}, 
		{ACC_INTERFACE,false},    {ACC_ABSTRACT,false},   {ACC_STRICT,false},
		{ACC_SYNTHETIC,false},    {ACC_ANNOTATION,false}, {ACC_ENUM,false}
	};

private:
	/*!
	   \brief Strings das flags de acesso.
	 */
	std::string AcessFlagsStr[18] = {"ACC_PUBLIC",       "ACC_PRIVATE",    "ACC_PROTECTED", 
						   			 "ACC_STATIC",       "ACC_FINAL",      "ACC_SUPER", 
						  			 "ACC_SYNCHRONIZED", "ACC_VOLATILE",   "ACC_BRIDGE", 
						   			 "ACC_TRANSIENT",    "ACC_VARARGS",    "ACC_NATIVE", 
						   			 "ACC_INTERFACE",    "ACC_ABSTRACT",   "ACC_STRICT",
						   			 "ACC_SYNTHETIC",    "ACC_ANNOTATION", "ACC_ENUM"};
};

/*!
   \brief Própria classe do arquivo.
   Delega a si processamentos da própria classe que o .class define.
 */
class ThisClass {
public:
	u2 idxClass; /*!< Índice da classe do arquivo no ConstantPool */
	std::string name; /*!< Nome da classe do ConstantPool */

	/*!
	   \brief Método construtor.
	 */
	ThisClass() {}

	/*!
	   \brief Define os valores dos atributos da classe.

	   \param idx Índice da classe no ConstantPool.
	   \param n Nome da classe.
	 */
	void set(u2 idx, std::string n){ name = n; idxClass = idx; }

	/*!
	   \brief Imprime os dados da classe em um Stream.
	   
	   \param out Stream onde imprimir os valores.
	 */
	void print(std::ostream &out) {
		out << "This Class.......: cp_info #" << std::dec << idxClass << " " << name << std::endl;
	}
};

/*!
   \brief Classe da qual o arquivo herda.
   Delega a si processamentos da super classe.
 */
class SuperClass {
public:
	u2 idxClass; /*!< Índice da super classe no ConstantPool. */
	std::string name; /*!< Nome da super classe. */

	/*!
	   \brief Método construtor padrão.
	 */
	SuperClass() {}

	/*!
	   \brief Define os valores dos atributos das classe.
	   
	   \param idx Índice da super classe no ConstantPool.
	   \param n Nome da super classe.
	 */
	void set(u2 idx, std::string n){ name = n; idxClass = idx; }

	/*!
	   \brief Imprime a super classe em um Stream.
	   
	   \param out  Stream onde imprimir.
	 */
	void print(std::ostream &out) {
		out << "Super Class......: cp_info #" << std::dec << idxClass << " " << name << std::endl;
	}
};

#endif
