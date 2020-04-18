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
	u4			 magic;				/*!< Assinatura do arquivo: 0xCAFEBABE */
	u2			 minorVersion;		/*!< Versão menor */
	u2			 majorVersion;		/*!< Versão maior */
	u2			 constantPoolCount;	/*!< Número de entradas na tabela constant_pool + 1 */
	ConstantPool constantPool;		/*!< Tabela de estruturas representando  constantes de string, nomes e outras constantes mencionadas no ClassFile.*/
	u2			 acessFlagsMask;	/*!< Máscara auxiliar para a inicialização do acessFlags */
	u2			 thisClassIdx; 		/*!< Índice para Tabela de Constantes para a inicialização do thisClass */
	u2			 superClassIdx; 	/*!< Se diferente de zero, índice para Tabela de Constantes para a inicialização do superClass */
	u2			 interfacesCount; 	/*!< Contador do número de interfaces */
	//u2		 interfaces; 		/*!< Vetor de interfaces */
	u2			 fieldsCount; 		/*!< Contador do número de Fields */
	Fields		 fields; 			/*!< Campos (Fields) da classe */
	u2			 methodsCount; 		/*!< Contador do número de métodos */
	Methods 	 methods; 			/*!< Métodos da classe */
	u2			 attributesCount; 	/*!< Contador do número de atributos */
	Attributes 	 attributes; 		/*!< Atributos da classe */

	// Additional
	Version 		version; 		/*!< Versão Java utilizada no arquivo .class */
	AcessFlags 		acessFlags; 	/*!< Flags de acesso da classe */
	ThisClass 		thisClass; 		/*!< Indica esta classe (definido a partir do ConstantPool) */
	SuperClass 		superClass;		/*!< Indica a super classe */

	/*!
	   \brief Faz a impressão do ClassFile, podendo ser em arquivo ou no terminal.
	   
	   \param mode Indica o modo da impressão (infile ou interminal)
	   \param argv Argumento que contém o nome do arquivo .class
	 */
	void print(u1 mode, std::string argv);

	/*!
	   \brief Imprime o ClassFile em um buffer.
	   
	   \param buf Buffer para impressão do arquivo.
	 */
	void printBuf(std::streambuf *buf);
};

#endif
