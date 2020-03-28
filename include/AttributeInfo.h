#ifndef ATTRIBUTEINFO_H
#define ATTRIBUTEINFO_H

#include "Definitions.h"

class AttributeInfo {
public:
    u2 			attributeNameIndex;	/*!<Deve ser uma estrutura CONSTANT_Utf8_info representando
    									o nome do atributo. */
    u4 			attributeLength;	/*!<Representa o comprimento da informação subsequente em bytes.
    									O comprimento não inclui os 6 bytes iniciais que contém os
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/    									itens AttributeNameIndex e attributeLength */
    union{					
		struct{
			u2 	constantvalueIndex;		/*!<O valor do item constantvalueIndex deve ser um índice
    	 									válido na tabela constant_pool. A entrada constant_pool
    	 									nesse índice fornece o valor constante representado por
    	 									este atributo. A entrada constant_pool deve ser do tipo
    	 									apropriado ao campo*/
		}ConstantValue;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
			u2 			maxStack;					/*<O valor do item max_stack fornece a profundidade máxima da
			 							   			   pilha de operandos deste método em qualquer ponto durante a
			 							   			   execução do método. */
		    u2 			maxLocals;					/*<O valor do item max_locals fornece o número de variáveis ​​locais
		     										   na matriz de variáveis ​​locais alocadas na invocação deste método,
		     										   incluindo as variáveis ​​locais usadas para passar parâmetros para 
		     										   o método em sua invocação.
													   O maior índice de variável local para um valor do tipo long ou double
													   é max_locals - 2. O maior índice de variável local para um valor de qualquer
													   outro tipo é max_locals - 1. */
		    u4 			codeLength;					/*<O valor do item code_length fornece o número de bytes na matriz de códigos
		    									 	   para este método.
													   O valor de code_length deve ser maior que zero (como a matriz de códigos não
													   deve estar vazia) e menor que 65536. */
		    u1 			*code;						/*<A matriz de códigos fornece os bytes reais do código da JVM que implementa o método.
													   Quando a matriz de códigos é lida na memória em uma máquina endereçável por bytes,
													   se o primeiro byte da matriz estiver alinhado em um limite de 4 bytes, os desvios
													   de 32 bits do comutador de tabela e de pesquisa serão alinhados em 4 bytes. */
		    u2 			exceptionTableLength;		/*<O valor do item exception_table_length fornece o número de entradas na tabela exception_table. */

		    struct{   
		    	u2 startPc;			/*<O valor do item start_pc indica o intervalo na matriz de códigos na qual o manipulador de exceções está ativo.
		    						   O valor de start_pc deve ser um índice válido na matriz de códigos do opcode de uma instrução. O valor de start_pc
		    						   deve ser menor que o valor de end_pc. O start_pc é inclusivo e end_pc é exclusivo; isto é, o manipulador de exceção
		    						   deve estar ativo enquanto o contador do programa estiver dentro do intervalo [start_pc, end_pc). */
		        u2 endPc;			/*<O valor do item end_pc indica o intervalo na matriz de códigos na qual o manipulador de exceções está ativo.
		        					   O valor de end_pc deve ser um índice válido na matriz de códigos do opcode de uma instrução ou deve ser igual
		        					   a code_length, o comprimento da matriz de códigos.*/
		        u2 handlerPc;		/*<O valor do item handler_pc indica o início do manipulador de exceções. O valor do item deve ser um índice válido
		         					   na matriz de códigos e deve ser o índice do código de operação de uma instrução. */
		        u2 catchType;		/*<Se o valor do item catch_type for diferente de zero, ele deverá ser um índice válido na tabela constant_pool.
		        	 			       A entrada constant_pool nesse índice deve ser uma estrutura CONSTANT_Class_info representando uma classe de
		        	 			       exceções que esse manipulador de exceção está designado para capturar. O manipulador de exceção será chamado
		        	 			       apenas se a exceção lançada for uma instância da classe especificada ou uma de suas subclasses.
									   Se o valor do item catch_type for zero, esse manipulador de exceções será chamado para todas as exceções. */
		    }*exceptionTable;		/*<Cada entrada na matriz exception_table descreve um manipulador de exceções
		     						   na matriz de códigos. A ordem dos manipuladores na matriz exception_table é
		     						   significativa */

		    u2 			  attributesCount;			/*<O valor do item attribute_count indica o número de atributos do atributo Code. */
		    AttributeInfo *attributes;				/*<Cada valor da tabela de atributos deve ser uma estrutura attribute_info.
											           Um atributo de código pode ter qualquer número de atributos opcionais associados a ele. */					
		}Code;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
			u2              numberOfEntries;		/*<O valor do item number_of_entries fornece o número de entradas stack_map_frame
													   na tabela de entradas.*/
    		stackMapFrame 	*entries;				/*<Cada entrada na tabela de entradas descreve um quadro de mapa de pilha do método.
    		 										   A ordem dos quadros do mapa de pilha na tabela de entradas é significativa.	*/
		}StackMapTable;

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
		 	u2 				numberOfExceptions;
		    u2 				*exceptionIndexTable;
		}Exceptions; 
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
		    u2 				numberOfClasses;
		    struct{   
		    	u2 		innerClassInfoIndex;
		        u2 		outerClassInfoIndex;
		        u2 		innerNameIndex;
		        u2 		innerClassAccessFlags;
		    }*classes;
		}InnerClasses;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
			u2 				classIndex;
   			u2 				methodIndex;
		}EnclosingMethod;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
		}Synthetic;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
			u2 				signatureIndex;
		}Signature;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
		    u2 				sourcefileIndex;
		}SourceFile;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct
		{
			u1 				*debug_extension;
		}SourceDebugExtension;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
		    u2 				lineNumberTableLength;
		    struct{
		        u2 		startPc;
		        u2 		lineNumber;	
		    }*lineNumberTable;
		}LineNumberTable;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
			u2 localVariableTableLength;
		    struct{   
		    	u2 	startPc;
		        u2 	length;
		        u2 	nameIndex;
		        u2 	descriptorIndex;
		        u2 	index;
		    }*localVariableTable;
		}LocalVariableTable;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
			u2 localVariableTypeTableLength;
		    struct{   
		    	u2 	startPc;
		        u2 	length;
		        u2 	nameIndex;
		        u2 	signatureIndex;
		        u2 	index;
		    }*localVariableTypeTable;
		}LocalVariableTypeTable;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
		}Deprecated;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
			u2         numAnnotations;
    		annotation *annotations;
		}RuntimeVisibleInvisibleAnnotations;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
			u1 		   numParameters;
		    struct{   
		    	u2         numAnnotations;
		        annotation *annotations;
		    }*parameterAnnotations;
		}RuntimeVisibleInvisibleParameterAnnotations;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
			u2              numAnnotations;
    		typeAnnotation *annotations;
		}RuntimeVisibleInvisibleTypeAnnotations;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
			elementValue defaultValue;
		}AnnotationDefault;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
			u2 				numBootstrapMethods;
		    {   u2 	bootstrapMethodRef;
		        u2 	numBootstrapArguments;
		        u2 	*bootstrapArguments;
		    }*bootstrapMethods;
		}BootstrapMethods;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
		struct{
			u1 				parametersCount;
		    struct{   
		    	u2 	nameIndex;
		        u2 	accessFlags;
		    }*parameters;
		}MethodParameters;
	}
}	


#endif
