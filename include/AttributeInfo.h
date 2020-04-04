#ifndef ATTRIBUTEINFO_H
#define ATTRIBUTEINFO_H

#include "Definitions.h"
#include "CpInfo.h"

class AttributeInfo;

class Attributes : public  std::vector<AttributeInfo*> {
public:
	Attributes() {}
	Attributes(std::ifstream& f, u2 attributesCount, ConstantPoolT constantPool); /*!< Tabela de estruturas dos atributos */
	std::string readName(u2 lenght, u1 *bytes);
};

class AttributeInfo {
public:
    u2	attributeNameIndex;	/*!< Indice para uma estrutura CONSTANT_Utf8_info representando o nome do atributo. */
    u4 	attributeLength;	/*!< Representa o comprimento da informação subsequente em bytes (não inclui os 6 bytes iniciais). */	   
    AttributeInfo() {}
    AttributeInfo(u2 idx, std::ifstream& f) : attributeNameIndex(idx), attributeLength(r4(f)) {}
    void generalInfo(u2 idx, std::ifstream& f);
};

class ConstantValue : public AttributeInfo {
public:
	ConstantValue(u2 idx, std::ifstream& f);
	u2 	constantvalueIndex;	/*!< Indice para a tabela constant_pool contendo o valor constante deste atributo. */
};

struct ExceptionTable{  /*< Cada entrada na matriz exception_table descreve um manipulador de exceções na matriz de códigos. */
    u2 startPc;         /*< Início do intervalo na matriz de códigos na qual o manipulador de exceções está ativo. */
    u2 endPc;           /*< Final do intervalo na matriz de códigos na qual o manipulador de exceções está ativo. */
    u2 handlerPc;       /*< Indica o início do manipulador de exceções. Deve ser o índice do opcode de uma instrução. */
    u2 catchType;       /*< Se diferente de zero, indica índice válido para uma estrutura CONSTANT_Class_info na tabela constant_pool, representando uma classe de
                           exceções que esse manipulador de exceção está designado para capturar. */
};        


class Code : public AttributeInfo {
public:
	Code(u2 idx, std::ifstream& f, ConstantPoolT constantPool);
	u2	maxStack;	/*< Profundidade máxima da pilha de operandos deste método em qualquer ponto durante a execução do método. */
    u2 	maxLocals;	/*< Número de variáveis ​​locais na matriz de variáveis ​​locais alocadas na invocação deste método. */
    u4 	codeLength;	/*< Número de bytes na matriz de códigos para este método. Deve ser entre zero e 65536. */
    u1 	*code;		/*< A matriz com os bytes reais do código da JVM que implementa o método. */
    u2 	exceptionTableLength;		/*< Número de entradas na tabela exception_table. */
    u2 	attributesCount;	/*< Indica o número de atributos do atributo Code. */
    Attributes attributes;	/*< Cada entrada é uma estrutura attribute_info. */					
    ExceptionTable *exceptionTable;
   };


class Exceptions : public AttributeInfo {
public:
	Exceptions(u2 idx, std::ifstream& f);
 	u2 	numberOfExceptions;
    u2 	*exceptionIndexTable;
}; 

class InnerClasses : public AttributeInfo {
public:
	InnerClasses(u2 idx, std::ifstream& f);
    u2 	numberOfClasses;
  struct{   
    	u2 	innerClassInfoIndex;
        u2 	outerClassInfoIndex;
        u2 	innerNameIndex;
        u2 	innerClassAccessFlags;
    }Classes;

    void rclasses(u2 nclasses);
};

class SourceFile : public AttributeInfo {
public:
	SourceFile(u2 idx, std::ifstream& f);
    u2 	sourcefileIndex;
};

struct LineNumberTableStr{
    u2  startPc;
    u2  lineNumber; 
};

class LineNumberTable : public AttributeInfo {
public:
	LineNumberTable(u2 idx, std::ifstream& f);
	u2 	lineNumberTableLength;
    LineNumberTableStr *lnTable;
};

struct LocalVariableTableStr{   
    u2  startPc;
    u2  length;
    u2  nameIndex;
    u2  descriptorIndex;
    u2  index;
};

class LocalVariableTable : public AttributeInfo {
public:
	LocalVariableTable(u2 idx, std::ifstream& f);
	u2 localVariableTableLength;
    LocalVariableTableStr *lvTable;
};


#endif
