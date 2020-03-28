#ifndef ATTRIBUTEINFO_H
#define ATTRIBUTEINFO_H

#include "Definitions.h"

class ConstantValueAttribute {
public:
    u2			attributeNameIndex;		/*!<Deve ser um indice válido na tabela constant_pool. 
    										            A entrada da constant_pool nesse indice deve ser uma 
    										            estrutura CONSTANT_Utf8_info representando a string
    										            "ConstantValue". */
    u4 			attributeLength;		/*!<O valor do item attributeLength de uma estrutura
    				 						            ConstantValueAttribute deve ser dois. */
    u2 			constantvalueIndex;		/*!<O valor do item constantvalueIndex deve ser um índice
    	 									              válido na tabela constant_pool. A entrada constant_pool
    	 									              nesse índice fornece o valor constante representado por
    	 									              este atributo. A entrada constant_pool deve ser do tipo
    	 									              apropriado ao campo*/
}

class Code_attribute {
public:
    u2 			attribute_name_index;
    u4 			attribute_length;
    u2 			max_stack;
    u2 			max_locals;
    u4 			code_length;
    u1 			code[code_length];
    u2 			exception_table_length;
    {   u2 start_pc;
        u2 end_pc;
        u2 handler_pc;
        u2 catch_type;
    } exception_table[exception_table_length];
    u2 attributes_count;
    attribute_info attributes[attributes_count];
}

class StackMapTable_attribute {
public:
    u2              attribute_name_index;
    u4              attribute_length;
    u2              number_of_entries;
    stack_map_frame entries[number_of_entries];
}

class AttributeInfo {
public:
    u2 			attributeNameIndex;	/*!<Deve ser uma estrutura CONSTANT_Utf8_info representando
    									              o nome do atributo. */
    u4 			attributeLength;	/*!<Representa o comprimento da informação subsequente em bytes.
    									            O comprimento não inclui os 6 bytes iniciais que contém os
    									            itens AttributeNameIndex e attributeLength */
    u1 			*info;				/*!< */
}


#endif
