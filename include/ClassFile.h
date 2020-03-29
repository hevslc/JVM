#ifndef CLASSFILE_H
#define CLASSFILE_H

#include "Definitions.h"
#include "CpInfo.h"
#include "AttributeInfo.h"
#include "FieldInfo.h"


/*! \class ClassFile reader.h "include/reader.h"
 *  \brief Classe que representa o arquivo .class. 
 *
 * As informações extraídas da leitura do arquivo são armazenadas nos atributos. 
 	Seus métodos são funções de leitura.
 */
class ClassFile{
public:
	u4				magic;					/*!< Assinatura do arquivo: 0xCAFEBABE */
	u2				minorVersion;			/*!< Versão menor */
	u2				majorVersion;			/*!< Versão maior */
	u2				constantPoolCount;		/*!< Número de entradas na tabela constant_pool + 1 */
	Cpinfo			*constantPool;			/*!< Tabela de estruturas representando string, nomes...*/
	//u2				acess_flags;
	//u2				this_class;
	//u2				super_class;
	//u2				interfaces_count;
	//u2				interfaces;
	//u2				fielsCount;
	//FieldInfo		field;
	//u2				methods_count;
	//method_info		methods;
	u2				attributesCount;
	AttributeInfo	attribute;


	u1 r1(std::ifstream& f);			/*!< Lê 1 byte do arquivo */
	u2 r2(std::ifstream& f);			/*!< Lê 2 byte do arquivo */
	u4 r4(std::ifstream& f);			/*!< Lê 4 byte do arquivo */
	void reading(std::ifstream& f);		/*!< Lê arquivo */

private:
	void rconstantPoolt(std::ifstream& f); /*!< Tabela de estruturas das constantes */

};



#endif