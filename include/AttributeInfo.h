#ifndef ATTRIBUTEINFO_H
#define ATTRIBUTEINFO_H

#include "Definitions.h"
#include "CpInfo.h"
#include "Opcode.h"

class AttributeInfo;

//! \class Attributes
/*! 
   \brief Vetor (tabela) dos atributos. Cada entrada é do tipo #AttributeInfo.
 */
class Attributes : public  std::vector<AttributeInfo*> {
public:
	Attributes() {}    /*!< Construtor auxiliar */
    //! Construtor
    /*!
    Lê toda a tabela de atributos do arquivo .class. Cada entrada tem a seguinte estrutura:
    ~~~~~{.cpp}
    AttributeInfo {
    u2 attributeNameIndex;
    u4 attributeLength;
    std::string name;
    u1 info[attributeLength];
    }
    ~~~~~
    Portanto, a atribuição dos atributos é feita verificando o nome decodificado da
     da entrada de índice attributeNameIndex da Tabela de Constantes.
    \param f Arquivo .class a ser lido.
    \param attributesCount Comprimento do vetor Attributes.
    \param constantPool Tabela de Constantes já lida do arquivo .class.
    */ 
	Attributes(std::ifstream& f, u2 attributesCount, ConstantPool constantPool);
    /*!
    Adiciona uma entrada do tipo #ConstantValue, construindo o objeto de acordo com o tipo de 
    constante (String, Inteiro, Float, Long ou Double). Portanto, após a leitura de tagValue,
    verifica  qual tipo, e constroi o objeto da classe #ConstantValue identificando o tipo
    do valor da constante.
    \param f Arquivo .class a ser lido.
    \param attributesCount Comprimento do vetor Attributes.
    \param constantPool Tabela de Constantes já lida do arquivo .class.
    \param idx Valor que será atribuído ao #attributeNameIndex.
    \param name String que será tribuída à #name.
    */ 
    void getConstantValue(std::ifstream& f, ConstantPool cpt, u2 idx, std::string name);
    /*!
    \brief Imprime o vetor Attributes.
    */
    void print(std::ostream& out, ConstantPool cpt);
};

//! \class AttributeInfo
/*! 
   \brief Classe base a ser herdada pelas classes das entradas do vetor Attributes, contendo membros gerais.
 */
class AttributeInfo {
public:
    u2	attributeNameIndex;	/*!< Indice para uma estrutura CONSTANT_Utf8_info representando o nome do atributo. */
    u4 	attributeLength;	/*!< Representa o comprimento da informação subsequente em bytes (não inclui os 6 bytes iniciais). */	   
    std::string name;       /*!< Nome decodificado do atributo. */
    AttributeInfo() {}      /*!< Construtor auxiliar. */
    //! Construtor
    /*!
    Lê os membros gerais attributeNameIndex e attributeLength. É usado em estruturas que contém
    apenas esses membros.
    \param idx valor a ser atribuído à #attributeNameIndex. 
    \param f Arquivo .class a ser lido.
    \param n Nome do atributo.
    */ 
    AttributeInfo(u2 idx, std::ifstream& f, std::string n) : attributeNameIndex(idx), attributeLength(r4(f)), name(n) {}
    void generalInfo(u2 idx, std::ifstream& f, std::string name);
    virtual void print(std::ostream& out, ConstantPool cpt) {(void)cpt; (void)out;}  /*!< Função virtual de impressão */
    virtual void print(std::ostream& out) {(void)out;} /*!< Função virtual de impressão */
};

//__________________________________________________________________
/*! 
   \brief Atributo para uma estrutura de campo (Field) 
   e representa o valor de uma expressão constante. É usado da seguinte forma:
        - Se a flag ACC_STATIC em item access_flags da estrutura AcessFlags estiver definido (verdadeiro), 
            o campo representado pela estrutura FieldInfo receberá o valor representado por seu 
            atributo ConstantValue como parte da inicialização da classe ou interface que declara 
            o campo. Isso ocorre antes da chamada do método de inicialização de classe ou interface 
            dessa classe ou interface.
        -  Caso contrário, a Java Virtual Machine deve ignorar silenciosamente o atributo.
*/
template<typename T>
class ConstantValue : public AttributeInfo {
public:
    T value;                /*!< \tparam value { Valor da constante, seja ela String, Inteiro, Float, Long ou Double } */
    u1 tagValue;            /*! Indica qual tipo do valor */
	u2 	constantvalueIndex;	/*!< Indice para a tabela constant_pool contendo o valor constante deste atributo. */
	ConstantValue() {}     /*!< Construtor auxiliar. */
    //! Construtor
    /*!
    Atribue valores dos parâmetros passados aos respectivos membros 
    \param tag Tipo do valor
    \param idx valor a ser atribuído à #attributeNameIndex. 
    \param l valor a ser atribuído à #attributeLength. 
    \param f Arquivo .class a ser lido.
    \param v Valor da constante.
    */ 
    ConstantValue(u1 tag, u2 idx, u4 l, std::string name, T v);
    void print(std::ostream& out); /*!< Imprime estrutura. */
};
//__________________________________________________________________
/*! 
Estrutura que contém informações do manipulador de exceções.
*/
class ExceptionTableInfo{
public:
    u2 startPc;         /*< Início do intervalo na matriz de códigos na qual o manipulador de exceções está ativo. */
    u2 endPc;           /*< Final do intervalo na matriz de códigos na qual o manipulador de exceções está ativo. */
    u2 handlerPc;       /*< Indica o início do manipulador de exceções. Deve ser o índice do opcode de uma instrução. */
    u2 catchType;       /*< Se diferente de zero, indica índice válido para uma estrutura CONSTANT_Class_info na tabela constant_pool, representando uma classe de
                            exceções que esse manipulador de exceção está designado para capturar. */
};
/*! 
Vetor (Tabela) com os manipuladores de exceções no array de código (code). A ordem é significativa.
*/
class ExceptionTable : public std::vector<ExceptionTableInfo*>{
public:
    ExceptionTable() {} /*< Contrutor auxiliar. */
    /*! 
    \brief Inicialização do vetor. Leitura das entradas do tipo #ExceptionTableInfo.
    \param f Arquivo .class a ser lido.
    \param len Número de entradas (comprimento do vetor).
    */
    ExceptionTable(std::ifstream& f, u2 len); 
    void print(std::ostream& out); /*< Número de entradas na tabela exception_table. */
};
/*! 
   Um atributo Code contém as instruções da Java Virtual Machine e informações auxiliares para um 
   método, incluindo um método de inicialização de instância ou um método de inicialização de classe 
   ou interface. Se o método for nativo ou abstrato, sua estrutura MethodInfo não deverá ter um 
   atributo Code em sua tabela de atributos. Caso contrário, sua estrutura MethodInfo deve ter 
   exatamente um atributo Code em sua tabela de atributos.
*/
class Code : public AttributeInfo {
public:
	u2	maxStack;	/*< Profundidade máxima da pilha de operandos deste método em qualquer ponto durante a execução do método. */
    u2 	maxLocals;	/*< Número de variáveis ​​locais na matriz de variáveis ​​locais alocadas na invocação deste método. */
    u4 	codeLength;	/*< Número de bytes na matriz de códigos para este método. Deve ser entre zero e 65536. */
    u1 	*code;		/*< A matriz com os bytes reais do código da JVM que implementa o método. */
    u2 	exceptionTableLength;		/*< Número de entradas na tabela exception_table. */
    u2 	attributesCount;	/*< Indica o número de atributos do atributo Code. */
    Attributes *attributes;	/*< Cada entrada é uma estrutura attribute_info. */					
    ExceptionTable *exceptionTable;
    //futuramente, atributo para Intruções do código (um vetor de objetos talvez)
    /*!
    \brief Constrói um objeto de Code, lendo valores do arquivo atribuindo-os aos membros.
    \param idx valor a ser atribuído à #attributeNameIndex. 
    \param f Arquivo .class a ser lido.
    \param constantPool Tabela de Constates já lida.
    \param  name Nome do atributo.
   */
	Code(u2 idx, std::ifstream& f, ConstantPool constantPool, std::string name);
    void print(std::ostream& out, ConstantPool cpt); /*!< Imprime estrutura. */
};
//__________________________________________________________________
/*! 
   Atributo pretencente a uma estrutura MethosInfo. Indica quais exceções verificadas 
   um método pode lançar. Pode haver no máximo um atributo de Exceções na tabela de 
   atributos de uma estrutura MethosInfo.
*/
class Exceptions : public AttributeInfo {
public:
 	u2 	numberOfExceptions;       /*!< Comprimento do array exceptionIndexTable. */
    /*! Tabela de índices válidos para a Tabela de Constantes, cujas entradas devem ser 
    do tipo Cpinfo contendo a estrutura Class, que representa um tipo de classe 
    que este método é declarado \a throw. */
    u2 	*exceptionIndexTable;    
    /*!
    \brief Constrói um objeto de Exceptions, lendo valores do arquivo atribuindo-os aos membros.
    \param idx valor a ser atribuído à #attributeNameIndex. 
    \param f Arquivo .class a ser lido.
    \param  name Nome do atributo.
   */ 
	Exceptions(u2 idx, std::ifstream& f, std::string name); 
    void print(std::ostream& out, ConstantPool cpt); /*!< Imprime estrutura. */
}; 
//__________________________________________________________________
/*! 
Estrutura que contém informações  para obter a classes relacionadas
*/
class ClassesInfo{
public:
    u2  innerClassInfoIndex;    /*!< Índice valido para Tabela de Constantes que conterá a classe. */
    u2  outerClassInfoIndex;    /*!< Classe ou interface cuja Classe atual é membro, se não existir o valor é zero. . */
    u2  innerNameIndex;         /*!< Se a classe não for anônima, é índice para Tabela de Constantes que conterá o nome da classe. Caso contrário, é zero.. */
    u2  innerClassAccessFlags;  /*!< Máscara para obter flags para permissões de acesso e propriedades da classe (ou interface). */
    AcessFlags acessFlags;      /*!< Flags de acesso da classe (ou interface. */
};

/*! 
Vetor do tipo #ClassesInfo.
*/
class Classes : public std::vector<ClassesInfo*>{
public:
    Classes() {} /*!< Construtor auxiliar. */
    /*!
    \brief Inicialização do vetor. Leitura das entradas do tipo #ClassesInfo.
    \param f Arquivo .class a ser lido.
    \param  len Número de entradas.
   */ 
    Classes(std::ifstream& f, u2 len);   
};
/*! 
  Se a Tabela de Constantes de uma classe ou interface \a C contiver pelo menos uma 
  entrada Cpindo com a estrutura Class que representa uma classe ou interface 
  que não seja membro de um pacote, deverá haver exatamente um atributo InnerClasses 
  na tabela de atributos de a estrutura ClassFile para \a C.
*/
class InnerClasses : public AttributeInfo {
public:
    u2 	    numberOfClasses;    /*!< Número de entradas no vetor classes da classe #Classes. */
    Classes *classes;           /*!< Vetor de ClassesInfo com informações das Classes ou Interfaces relacionadas */
	/*!
    \brief Constrói um objeto de InnerClasses, lendo valores do arquivo atribuindo-os aos membros.
    \param idx valor a ser atribuído à #attributeNameIndex. 
    \param f Arquivo .class a ser lido.
    \param  name Nome do atributo.
   */ 
    InnerClasses(u2 idx, std::ifstream& f, std::string name);
    void print(std::ostream& out, ConstantPool cpt); /*!< Imprime estrutura. */
};
//__________________________________________________________________
/*! 
  Contém nome do arquivo de origem
*/
class SourceFile : public AttributeInfo {
public:
    u2 	sourcefileIndex;    /*!< Índice valido para Tabela de Constantes que conterá o nome do arquivo. */
	SourceFile() {}         /*!< Contrutor auxiliar. */ 
    /*!
    \brief Constrói um objeto de SourceFile, lendo valores do arquivo atribuindo-os aos membros.
    \param idx valor a ser atribuído à #attributeNameIndex. 
    \param f Arquivo .class a ser lido.
    \param  name Nome do atributo.
   */   
    SourceFile(u2 idx, std::ifstream& f, std::string name);
    void print(std::ostream& out, ConstantPool cpt); /*!< Imprime estrutura. */
};
//__________________________________________________________________
/*! 
Estrutura com informações indicando que o número da linha no arquivo de origem 
original é alterado em um determinado ponto na matriz de códigos. 
*/
class LineNumberTableStrInfo{
public:
    u2  startPc;    /*!< Indicar o índice no array de códigos na qual o código para uma nova linha no arquivo de origem original começa. */ 
    u2  lineNumber; /*!< Número da linha correspondente no arquivo de origem original. */ 
};
/*! 
Vetor do tipo #LineNumberTableStrInfo.
*/
class LineNumberTableStr : public std::vector<LineNumberTableStrInfo*>{
public:
    LineNumberTableStr() {} /*!< Contrutor auxiliar. */ 
    /*!
    \brief Inicialização do vetor. Leitura das entradas do tipo #LineNumberTableStrInfo.
    \param f Arquivo .class a ser lido.
    \param  len Número de entradas.
   */ 
    LineNumberTableStr(std::ifstream& f, u2 len);   
};
/*! 
Estrutura com informações a serem usadas pelos depuradores para determinar qual 
parte do array de códigos corresponde a um determinado número de linha no arquivo 
de origem original. e vários atributos LineNumberTable estiverem presentes na tabela
de atributos de um atributo Code, eles poderão aparecer em qualquer ordem.
Pode haver mais de um atributo LineNumberTable por linha de um arquivo de origem 
na tabela de atributos de um atributo de Código. Ou seja, os atributos LineNumberTable 
podem juntos representar uma determinada linha de um arquivo de origem e não 
precisam ser individuais com as linhas de origem.
*/
class LineNumberTable : public AttributeInfo {
public:
	u2 	lineNumberTableLength;     /*!< Tamanho do atributo, sem contar os 6 bytes iniciais. */
    LineNumberTableStr *lnTable;   /*!< Vetor com informações de cada linha do código. */
	/*!
    \brief Constrói um objeto de LineNumberTable, lendo valores do arquivo atribuindo-os aos membros.
    \param idx valor a ser atribuído à #attributeNameIndex. 
    \param f Arquivo .class a ser lido.
    \param  name Nome do atributo.
   */  
    LineNumberTable(u2 idx, std::ifstream& f, std::string name);
    void print(std::ostream& out); /*!< Imprime estrutura. */
};
//__________________________________________________________________
class LocalVariableTableStrInfo{   
public:
    u2  startPc;            /*!< A variável local especificada deve ter um valor nos índices da matriz de códigos no intervalo [startPc, startPc + length). */ 
    u2  length;             /*!< A variável local especificada deve ter um valor nos índices da matriz de códigos no intervalo [startPc, startPc + length). */ 
    u2  nameIndex;          /*!< Índice para Tabela de Constantes que conterá o nome da variável local. */ 
    u2  descriptorIndex;   /*!< Índice para Tabela de Constantes que conterá o descritor de campo que codifica o tipo de uma variável local no programa de origem. */ 
    /*! A variável local especificada deve estar no índice na matriz de variáveis 
    locais do quadro atual. Se a variável local no índice for do tipo duplo ou 
    longo, ela ocupará o índice e o índice + 1. */ 
    u2  index;               
};
/*! 
Vetor do tipo #LocalVariableTableStrInfo.
*/
class LocalVariableTableStr : public std::vector<LocalVariableTableStrInfo*>{
public:
    LocalVariableTableStr() {}  /*!< Contrutor auxiliar. */
    /*!
    \brief Inicialização do vetor. Leitura das entradas do tipo #LocalVariableTableStrInfo.
    \param f Arquivo .class a ser lido.
    \param  len Número de entradas.
   */  
    LocalVariableTableStr(std::ifstream& f, u2 len); 
};
/*! 
Estrutura com informações a serem usadas pelos depuradores para determinar o valor 
de uma determinada variável local durante a execução de um método.
Se vários atributos LocalVariableTable estiverem presentes na tabela de atributos 
de um atributo Code, eles poderão aparecer em qualquer ordem. Pode haver não mais 
de um atributo LocalVariableTable por variável local na tabela de atributos de um 
atributo Code.
*/
class LocalVariableTable : public AttributeInfo {
public:
	u2 localVariableTableLength;       /*!< Tamanho do atributo, sem contar os 6 bytes iniciais. */
    LocalVariableTableStr *lvTable;    /*!< Vetor com da variável local. */
	/*!
    \brief Constrói um objeto de LocalVariableTable, lendo valores do arquivo atribuindo-os aos membros.
    \param idx valor a ser atribuído à #attributeNameIndex. 
    \param f Arquivo .class a ser lido.
    \param  name Nome do atributo.
   */  
    LocalVariableTable(u2 idx, std::ifstream& f, std::string name);
    void print(std::ostream& out, ConstantPool cpt); /*!< Imprime estrutura. */
};


#endif
