#ifndef FIELDINFO_H
#define FIELDINFO_H

#include "CpInfo.h"
#include "Definitions.h"
#include "AttributeInfo.h"

/*!
   \brief Estrutura de um field na JVM.
 */
class FieldInfo{
public:
	AcessFlags 				accessFlags; 		/*!<Máscara de hexas especificando permissões de acesso e propriedades do campo.  */
	u2 						nameIndex;			/*!<Representa um nome simples de field. */
	u2 						descriptorIndex;	/*!<Representa um descritor de campo válido. */
	u2 						attributesCount;	/*!<Número de atributos do campo */
	Attributes 				*attributes;		/*!<Formato dos atributos */

	std::string name;       					/*!< Nome do field */
  	std::string descriptor; 					/*!< Descritor do field */

	/*!
     \brief Inicializa um objeto FieldInfo.
     Basicamente decodifica nome e descritor do field.    
     \param cp Tabela pool de constantes.
   */
	void init(ConstantPool &cp);

	/*!
     \brief Imprime os dados do field em uma saída.    
     \param out Saída onde o field será impresso.
     \param cp Tabela pool de constantes.
   */
	void print(std::ostream &out, ConstantPool &cp);

private:
	 /*!
     \brief Imprime o nome do field em uma saída.    
     \param out Local onde será impresso o nome do field.
   */
	 void printName(std::ostream &out);

	 /*!
     \brief Imprime o descritor do field.    
     \param out Onde será impresso o field.
   */
	 void printDescriptor(std::ostream &out);

};



/*!
   \brief Vetor de fields da JVM.
 */
class Fields : public  std::vector<FieldInfo *> {
public:
	Fields() {}

	/*!
     \brief Constrói um novo vetor de fields.

     \param f           	 Arquivo .class.
     \param fieldsCount      Número de Fields.
     \param constantPool     Pool de constantes.
   */
	Fields(std::ifstream& f, u2 fieldsCount ,ConstantPool constantPool);

	 /*!
     \brief Imprime o vetor.
   */
	void print(std::ostream& out, ConstantPool cp);
};

#endif
