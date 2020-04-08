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
	~ClassFile();
	
	u4				magic;					/*!< Assinatura do arquivo: 0xCAFEBABE */
	u2				minorVersion;			/*!< Versão menor */
	u2				majorVersion;			/*!< Versão maior */
	u2				constantPoolCount;		/*!< Número de entradas na tabela constant_pool + 1 */
	ConstantPoolT	constantPool;			/*!< Tabela de estruturas representando string, nomes...*/
	u2				acess_flags;
	u2				this_class;
	u2				super_class;
	u2				interfaces_count;
	//u2				interfaces;
	u2				fieldsCount;
	Fields			fields;
	u2				methods_count;
	Methods* 	    methods;
	u2				attributesCount;
	Attributes 		attribute;

	//Additional
	std::map<u2, bool> acessFlags{ {ACC_PUBLIC, false}, {ACC_FINAL, false},
			{ACC_SUPER, false}, {ACC_INTERFACE, false}, {ACC_ABSTRACT, false},
			{ACC_SYNTHETIC, false}, {ACC_ANNOTATION, false}, {ACC_ENUM, false}};	



	void reading(std::ifstream& f);		/*!< Lê arquivo */

	//Decoding
	void racessFlags(u2 mask);

private:
	

};



#endif
