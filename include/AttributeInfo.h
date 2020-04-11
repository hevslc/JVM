#ifndef ATTRIBUTEINFO_H
#define ATTRIBUTEINFO_H

#include "Definitions.h"
#include "CpInfo.h"

class AttributeInfo;

class Attributes : public  std::vector<AttributeInfo*> {
public:
	Attributes() {}
	Attributes(std::ifstream& f, u2 attributesCount, ConstantPool constantPool); /*!< Tabela de estruturas dos atributos */
	std::string readName(Cpinfo cpi);
    void print(ConstantPool cpt);
};

class AttributeInfo {
public:
    u2	attributeNameIndex;	/*!< Indice para uma estrutura CONSTANT_Utf8_info representando o nome do atributo. */
    u4 	attributeLength;	/*!< Representa o comprimento da informação subsequente em bytes (não inclui os 6 bytes iniciais). */	   
    std::string name;
    AttributeInfo() {}
    AttributeInfo(u2 idx, std::ifstream& f, std::string n) : attributeNameIndex(idx), attributeLength(r4(f)), name(n) {}
    void generalInfo(u2 idx, std::ifstream& f, std::string name);
    //virtual void print(ConstantPool cpt) {(void)cpt; }
};

//__________________________________________________________________
class ConstantValue : public AttributeInfo {
public:
	ConstantValue(u2 idx, std::ifstream& f, std::string name);
    //void print(ConstantPool cpt);
	u2 	constantvalueIndex;	/*!< Indice para a tabela constant_pool contendo o valor constante deste atributo. */
};
//__________________________________________________________________
class ExceptionTableInfo{
public:
    u2 startPc;         /*< Início do intervalo na matriz de códigos na qual o manipulador de exceções está ativo. */
    u2 endPc;           /*< Final do intervalo na matriz de códigos na qual o manipulador de exceções está ativo. */
    u2 handlerPc;       /*< Indica o início do manipulador de exceções. Deve ser o índice do opcode de uma instrução. */
    u2 catchType;       /*< Se diferente de zero, indica índice válido para uma estrutura CONSTANT_Class_info na tabela constant_pool, representando uma classe de
                            exceções que esse manipulador de exceção está designado para capturar. */
};

class ExceptionTable : public std::vector<ExceptionTableInfo*>{
public:
    ExceptionTable() {}
    ExceptionTable(std::ifstream& f, u2 len);
    //void print();
};
 
class Code : public AttributeInfo {
public:
	Code(u2 idx, std::ifstream& f, ConstantPool constantPool, std::string name);
    //void print(ConstantPool cpt);
	u2	maxStack;	/*< Profundidade máxima da pilha de operandos deste método em qualquer ponto durante a execução do método. */
    u2 	maxLocals;	/*< Número de variáveis ​​locais na matriz de variáveis ​​locais alocadas na invocação deste método. */
    u4 	codeLength;	/*< Número de bytes na matriz de códigos para este método. Deve ser entre zero e 65536. */
    u1 	*code;		/*< A matriz com os bytes reais do código da JVM que implementa o método. */
    u2 	exceptionTableLength;		/*< Número de entradas na tabela exception_table. */
    u2 	attributesCount;	/*< Indica o número de atributos do atributo Code. */
    Attributes *attributes;	/*< Cada entrada é uma estrutura attribute_info. */					
    ExceptionTable *exceptionTable;
};
//__________________________________________________________________
class Exceptions : public AttributeInfo {
public:
	Exceptions(u2 idx, std::ifstream& f, std::string name);
    //void print(ConstantPool cpt);
 	u2 	numberOfExceptions;
    u2 	*exceptionIndexTable;
}; 
//__________________________________________________________________
class ClassesInfo{
public:
    u2  innerClassInfoIndex;
    u2  outerClassInfoIndex;
    u2  innerNameIndex;
    u2  innerClassAccessFlags;public:
};
//__________________________________________________________________
class Classes : public std::vector<ClassesInfo*>{
public:
    Classes() {}
    Classes(std::ifstream& f, u2 len);   
};

class InnerClasses : public AttributeInfo {
public:
	InnerClasses(u2 idx, std::ifstream& f, std::string name);
    //void print(ConstantPool cpt);
    u2 	    numberOfClasses;
    Classes *classes;   
};
//__________________________________________________________________
class SourceFile : public AttributeInfo {
public:
	SourceFile(u2 idx, std::ifstream& f, std::string name);
    //void print(ConstantPool cpt);
    u2 	sourcefileIndex;
};
//__________________________________________________________________
class LineNumberTableStrInfo{
public:
    u2  startPc;
    u2  lineNumber; 
};

class LineNumberTableStr : public std::vector<LineNumberTableStrInfo*>{
public:
    LineNumberTableStr() {}
    LineNumberTableStr(std::ifstream& f, u2 len);   
    //void print(); 
};

class LineNumberTable : public AttributeInfo {
public:
	LineNumberTable(u2 idx, std::ifstream& f, std::string name);
    //void print(ConstantPool cpt);
	u2 	lineNumberTableLength;
    LineNumberTableStr *lnTable;
};
//__________________________________________________________________
class LocalVariableTableStrInfo{   
public:
    u2  startPc;
    u2  length;
    u2  nameIndex;
    u2  descriptorIndex;
    u2  index;
};

class LocalVariableTableStr : public std::vector<LocalVariableTableStrInfo*>{
public:
    LocalVariableTableStr() {}
    LocalVariableTableStr(std::ifstream& f, u2 len); 
};

class LocalVariableTable : public AttributeInfo {
public:
	LocalVariableTable(u2 idx, std::ifstream& f, std::string name);
    //void print(ConstantPool cpt);
	u2 localVariableTableLength;
    LocalVariableTableStr *lvTable;
};


#endif
