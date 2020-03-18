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







#endif
