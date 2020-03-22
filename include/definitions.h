#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <fstream>
#include <iostream>
#include <cstdint>

typedef uint8_t 	u1;					/*!< Tipo de dado (8 bits)  */
typedef uint16_t	u2;					/*!< Tipo de dado (16 bits) */
typedef uint32_t 	u4;					/*!< Tipo de dado (32 bits) */

//! Método reading
/*!
	Cada item na tabela constant_pool deve começar com uma tag de 1 byte, 
	indicando o tipo de entrada cp_info. Tags:
*/ 
#define CONSTANT_Class 				7	
#define CONSTANT_Fieldref 			9	
#define CONSTANT_Methodref 			10	
#define CONSTANT_InterfaceMethodref 11	
#define CONSTANT_String 			8	
#define CONSTANT_Integer 			3	
#define CONSTANT_Float 				4	
#define CONSTANT_Long 				5	
#define CONSTANT_Double 			6	
#define CONSTANT_NameAndType 		12	
#define CONSTANT_Utf8 				1

/*!
   \brief Flags de acesso de métodos.
   Indica a disponibilidade de acesso de um método.
 */
enum MethodAccessFlag
{
	ACC_PUBLIC       = 0x0001,  /*!< Declarado público; pode ser acessada fora de seu pacote. */
	ACC_PRIVATE      = 0x0002,  /*!< Declarado privado; acessível apenas dentro da classe em que é definido. */
	ACC_PROTECTED    = 0x0004,  /*!< Declarado protegido; pode ser acessado dentro de classes derivadas. */
	ACC_STATIC       = 0x0008,  /*!< Declarado estático. */
	ACC_FINAL        = 0x0010,  /*!< Declarado final; não pode ser sobrescrito. */
	ACC_SYNCHRONIZED = 0x0020,  /*!< Declarado synchronized; chamada é envolvida pelo uso de um monitor. */
	ACC_BRIDGE       = 0x0040,  /*!< Um método bridge, gerado pelo compilador. */
	ACC_VARARGS      = 0x0080,  /*!< Declarado com número variável de argumentos. */
	ACC_NATIVE       = 0x0100,  /*!< Declarado nativo; implementado em outra linguagem não sendo Java. */
	ACC_ABSTRACT     = 0x0400,  /*!< Declarado abstrato; nenhuma implementação é fornecida. */
	ACC_STRICT       = 0x0800,  /*!< Declarado strictfp; modo floating-point é FP-strict. */
	ACC_SYNTHETIC    = 0x1000,  /*!< Declarado sitético; não está presente no código fonte. */
}

#endif
