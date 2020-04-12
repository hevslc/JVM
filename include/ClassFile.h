#ifndef CLASSFILE_H
#define CLASSFILE_H

#include "Definitions.h"
#include "CpInfo.h"
#include "AttributeInfo.h"
#include "FieldInfo.h"
#include "MethodInfo.h"


/*! \class ClassFile reader.h "include/reader.h"
 *  \brief Classe que representa o arquivo .class. 
 *
 * As informações extraídas da leitura do arquivo são armazenadas nos atributos. 
 	Seus métodos são funções de leitura.
 */
class ClassFile{
public:
	/*!
	   \brief Constrói um novo objeto ClassFile.
	   Lê todo o conteúdo do arquivo .class armazenando as informações 
	   no objeto ClassFile em seus respectivos atributos.

	   \param f Arquivo .class a ser lido.
	   \sa ClassFile::rconstantPoolt(std::ifstream&)
	 */
	ClassFile(std::ifstream &f);

	u4				magic;					/*!< Assinatura do arquivo: 0xCAFEBABE */
	u2				minorVersion;			/*!< Versão menor */
	u2				majorVersion;			/*!< Versão maior */
	u2				constantPoolCount;		/*!< Número de entradas na tabela constant_pool + 1 */
	ConstantPool	constantPool;			/*!< Tabela de estruturas representando string, nomes...*/
	u2				acessFlagsMask;
	u2				thisClass;
	u2				superClass;
	u2				interfacesCount;
	//u2			interfaces;
	u2				fieldsCount;
	Fields			fields;
	u2				methodsCount;
	Methods 	    methods;
	u2				attributesCount;
	Attributes 		attributes;

	//Additional
	Version 		version;
	AcessFlags 		acessFlags;

	

	//Print
	void print(u1 mode, std::string argv);
	void printBuf(std::streambuf  *buf);
};




#endif
