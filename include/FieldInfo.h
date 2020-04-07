#ifndef FIELDINFO_H
#define FIELDINFO_H

#include "CpInfo.h"
#include "Definitions.h"
#include "AttributeInfo.h"

class FieldInfo{
public:
	u2 						accessFlags; 		/*!<Máscara de hexas especificando permissões de acesso e propriedades do campo.  */
	u2 						nameIndex;			/*!<Representa um nome simples de field. */
	u2 						descriptorIndex;	/*!<Representa um descritor de campo válido. */
	u2 						attributesCount;	/*!<Número de atributos do campo */
	Attributes 				*attributes;		/*!<Formato dos atributos */
};

class Fields : public  std::vector<FieldInfo *> {
public:
	Fields() {}
	Fields(std::ifstream& f, u2 fieldsCount ,ConstantPoolT constantPool);
	void printFields();

private:
	u2 readFieldsCount(u2 fieldsCount);
};

#endif
