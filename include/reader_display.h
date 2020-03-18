#ifndef READER_H
#define READER_H

#include "definitions.h"

//! \class Cpinfo reader_display.h "include/reader_display.h"
/*!
	Classe com a estrutura de entrada da tabela constant_pool no seguinte formato geral:
	cp_info {
	u1 tag;
	u1 info[ ];
	}
	~~~~~
	Cada item na tabela constant_pool deve começar com uma tag de 1 byte, indicando o 
	tipo de entrada cp_info. O conteúdo da matriz de informações varia com o valor da tag.
	Cada byte de tag deve ser seguido por dois ou mais bytes, 
	fornecendo informações sobre a constante específica. 
	O formato das informações adicionais varia com o valor da tag.
	A estrutura union torna Cpinfo adaptável de acordo com a tag. 
*/
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
		}FieldMethInter;

		struct{
			u2 stringIndex;
		}String;

		struct{
			u4 bytes;
		}IntegerFloat;

		struct{
			u4 highBytes;
			u4 lowBytes;
		}LongDouble;

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

/*! \class ClassFile reader_display.h "include/reader_display.h"
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
	//u2				fiels_count;
	//field_info		field;
	//u2				methods_count;
	//method_info		methods;
	//u2				attributes_count;
	//attribute_info	attribute;


	u1 r1(std::ifstream& f);			/*!< Lê 1 byte do arquivo */
	u2 r2(std::ifstream& f);			/*!< Lê 2 byte do arquivo */
	u4 r4(std::ifstream& f);			/*!< Lê 4 byte do arquivo */
	void reading(std::ifstream& f);		/*!< Lê arquivo */

private:
	void rconstantPoolt(std::ifstream& f); /*!< Tabela de estruturas das constantes */

};



#endif