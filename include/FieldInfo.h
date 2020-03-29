#ifndef FIELDINFO_H
#define FIELDINFO_H

#include "Definitions.h"

class FieldInfo {
public:
	u2 						accessFlags; 		/*!<Máscara de hexas especificando permissões de acesso e propriedades do campo.  */
	u2 						nameIndex;			/*!<Representa um nome simples de field. */
	u2 						descriptorIndex;	/*!<Representa um descritor de campo válido. */
	u2 						attributesCount;	/*!<Número de atributos do campo */
	attributeInfo 			*attributes;		/*!<Formato dos atributos */
}

enum Flags : u4{
	ACC_PUBLIC    = 0x0001,    /*!<Declarada pública: pode ser acessada de fora do pacote.*/
	ACC_PRIVATE   = 0x0002,    /*!<Declarada privada: contexto restrito à definição da classe.*/
	ACC_PROTECTED = 0x0004,    /*!<Declarada privada: contexto restrito à definição da classe.*/
	ACC_STATIC    = 0x0008,    /*!<Declarada estática: variável de classe e não de instância.*/
	ACC_FINAL     = 0x0010,    /*!<Declarada final: não pode ter seu valor alterado após a iniciação.*/
	ACC_VOLATILE  = 0x0040,    /*!<Declarada volátil: não pode ser colocada em cache. A Thread que a 
								usa deve conciliar sua cópia dessa variável com a mestra toda vez que for acessá-la.*/
	ACC_TRANSIENT = 0x0080,    /*!<Declarada transiente: não pode ser lida ou gravada por um gerente de objetos 
								persistente. (Reserva para uso futuro da Sun)*/
	ACC_SYNTHETIC = 0x1000,    /*!<Declarada sintética: não presente no código fonte.*/ 
	ACC_ENUM      = 0x4000     /*!<Declarada como um elemento de um enum.*/ 
};


#endif