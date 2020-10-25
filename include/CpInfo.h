#ifndef CPINFO_H
#define CPINFO_H

#include "Definitions.h"

//! \class Cpinfo 
/*!
	Classe representando a estrutura de entrada da tabela constant_pool no seguinte formato geral:
	~~~~~{.cpp}
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
	u1 tag=0;				/*!< Informa qual tipo de estrutura. */
	union{					
		struct{
			/*! \brief Índice para Tabela de Constantes cuja entrada conterá o nome codificado 
			da classe ou interface. */
			u2 nameIndex;	
		}Class;				/*!< Estrutura que representa uma classe ou interface. */

		struct{
			/*! \brief Índice para Tabela de Constantes cuja entrada conterá o nome codificado 
   				da classe ou interface que possui o campo ou método como membro. */
			u2 classIndex;
			/*! \brief Índice para Tabela de Constantes cuja entrada conterá a estrutura NameAndType 
   				com o nome e o descritor do campo ou método. */
			u2 nameTypeIndex;
		}FieldMethInter;	/*!< Estrutura que representa campo, método ou inerface. */

		struct{
			/*! \brief Índice para Tabela de Constantes cuja entrada conterá o nome codificado 
			cujo objeto String deve ser inicializado. */
			u2 stringIndex;
		}String;			/*!< Estrutura que representa objetos constantes do tipo String. */

		struct{
			u4 bytes;		/*!< Bytes do valor da constante. */
			int nint;		/*!< Valor inteiro decodificado. */
		}Integer;			/*!< Estrutura que representa constantes numéricas do tipo \a int. */

		struct{
			u4 bytes;		/*!< Bytes do valor da constante \a float no formato único de ponto flutuante IEEE 754. */
			float nfloat;	/*!< Valor \a float decodificado. */
		}Float;				/*!< Estrutura que representa constantes numéricas do tipo \a float. */

		struct{
			u4 highBytes;	/*!< Bytes mais significativos do valor numérico (Big-endian)*/
			u4 lowBytes;	/*!< Bytes menos significativos do valor numérico (Big-endian)*/
			long nlong;		/*!< Valor numérico do tipo \a long decodificado: ((long) #highBytes << 32) + #lowBytes */
		}Long;				/*!< Estrutura que representa constantes numéricas do tipo \a long. */

		struct{
			u4 highBytes;	/*!< Bytes mais significativos do valor numérico (Big-endian) de ponto flutuante IEEE 754 */
			u4 lowBytes;	/*!< Bytes menos significativos do valor numérico (Big-endian) de ponto flutuante IEEE 754*/
			double ndouble;	/*!< Valor numérico do tipo \a double decodificado. */
		}Double;			/*!< Estrutura que representa constantes numéricas do tipo \a double. */

		struct{
			/*! \brief Índice para Tabela de Constantes cuja entrada conterá o nome codificado 
			do campo ou método. */
			u2 nameIndex;
			/*! \brief Índice para Tabela de Constantes cuja entrada conterá o descritor
			codificado do campo ou método. */
			u2 descriptorIndex; 
		}NameAndType;		/*!< Estrutura que representa um campo ou método sem indicar a qual classe ou tipo de interface pertence. */

		struct{
			u2 lenght;		/*!< Número de bytes do array #bytes. */
			u1 *bytes;		/*!< Array de bytes contendo os bytes da string. */
		}Utf8;				/*!< Estrutura que representa bytes de strings codificadas em UTF-8 modificado. */

		struct{
			u1 referenceKind;  /*!< tipo desse identificador de método, que caracteriza seu comportamento de bytecode. */
			u2 referenceIndex; 
		}MethodHandle;		/*!< Estrutura que representa um identificador de método. */
	};
};

//! \class ConstantPool
/*! 
   \brief Vetor (tabela) das constantes. Cada entrada é do tipo #Cpinfo.
 */
class ConstantPool : public std::vector<Cpinfo> {
public:
	ConstantPool() {};  /*!< Construtor auxiliar */
	//! Construtor
	/*!
	Lê toda a tabela de constantes do arquivo .class armazenando as informações 
	no objeto da classe cpinfo em seus respectivos atributos.
	Cada entrada tem a seguinte estrutura:
	~~~~~{.cpp}
	Cpinfo {
	u1 tag;
	u1 info[ ];
	}
	~~~~~
	Portanto, a atribuição das constantes é feita verificando a tag, o qual 
	define o tipo da informação em cp_info.
	\param f Arquivo .class a ser lido.
	\param constantPoolCount Comprimento do vetor.
	\sa #CONSTANT_Class, #CONSTANT_Fieldref, #CONSTANT_Methodref, #CONSTANT_InterfaceMethodref,
		#CONSTANT_String, #CONSTANT_Integer, #CONSTANT_Float, #CONSTANT_Long, #CONSTANT_Double,
		#CONSTANT_NameAndType, #CONSTANT_Utf8
	*/ 
	ConstantPool(std::ifstream& f, u2 constantPoolCount); /*!< Tabela de estruturas das constantes */
	/*!
    \brief Imprime o vetor ConstantPool.
    */
	void print(std::ostream& out);
	/*!
    \brief Constrói uma string com os bytes da estrutura #Utf8 da entrada #Cpinfo.
    \param cpi Entrada #Cpinfo com a estrutura #Utf8 .
    \return String com o nome decodificado.
    */
	std::string Bytes2Str(Cpinfo cpi);
	/*!
    \brief Encontra a string da estrutura #Utf8 da entrada #Cpinfo cujo índice é dado à função.
    \param idxUtf8 índice da Tabela de Constantes com a entrada #Cpinfo com a estrutura #Utf8 requerida.
    \return String com o nome decodificado.
    \sa Bytes2Str()
    */
	std::string getUtf8Str(u2 idxUtf8);
	/*!
    \brief Encontra a string da estrutura #Class da entrada #Cpinfo cujo índice é dado à função.
    \param idxClass índice da Tabela de Constantes com a entrada #Cpinfo com a estrutura #Class requerida.
    \return String com o nome decodificado.
    \sa getUtf8Str()
    */
	std::string getUtf8Class(u2 idxClass);
	/*!
    \brief Encontra a string da estrutura #NameAndType da entrada #Cpinfo cujo índice é dado à função.
    \param idxNameType índice da Tabela de Constantes com a entrada #Cpinfo com a estrutura #NameAndType requerida.
    \return String com o descritor decodificado.
    \sa getUtf8Str()
    */
	std::string getDescriptor(u2 idxNameType);
	/*!
    \brief Encontra a string da estrutura #NameAndType da entrada #Cpinfo cujo índice é dado à função.
    \param idxNameType índice da Tabela de Constantes com a entrada #Cpinfo com a estrutura #NameAndType requerida.
    \return String com o nome decodificado do campo ou método.
    \sa getUtf8Str()
    */
	std::string getNNameAndType(u2 idxNameType);
};

#endif // _CP_INFO_H_
