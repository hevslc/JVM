#ifndef CPINFO_H
#define CPINFO_H

#include "Definitions.h"

//! \class Cpinfo reader.h "include/reader.h"
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
			void print(){
				std::cout << "Name: " << std::endl;
				for(u1 i=0; i<lenght; i++) std::cout << bytes[i];
				std::cout << std::endl;
			}
		}Utf8;

		struct{
			u1 referenceKind;
			u2 referenceIndex;
		}MethodHandle;
	};
};


class ConstantPoolT : public std::vector<Cpinfo> {
public:
	ConstantPoolT() {};
	ConstantPoolT(std::ifstream& f, u2 constantPoolCount); /*!< Tabela de estruturas das constantes */
	void print();
};

#endif