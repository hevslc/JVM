#ifndef _OPCODE_H_
#define _OPCODE_H_

#include "Definitions.h"
#include "CpInfo.h"

/*!
   \brief Classe base para Opcodes.
   Ainda não está pronta para ser uma classe completa para instruções, apenas para opcodes.

   NOTA: Caso seja necessário que um opcode acesse outros elementos externos (CpInfo por
   exemplo) é só adicionar um ponteiro para o elemento como atributo dessa classe, criar
   um atributo binário para indicar a dependência e uma função para fazer a injeção da
   dependência.
   
 */
class Opcode
{
    public:
        bool knowsCode = false; /*!< Indica se o objeto depende do array de códigos/opcodes */

        Opcode(std::string name);
        virtual ~Opcode() = default;
        virtual std::string getString();

        /*!
           \brief Injeção de dependência do array de códigos.
           
           \param code Array com os códigos/opcodes.
           \param position Posição do opcode que se quer acessar.
         */
        void inline injectCode(u1 code[], u4 &position, ConstantPool cp)
        {
            this->code = code;
            this->position = &position;
            this->cp = cp;
        }

    protected:
        std::string name; /*!< Nome do Opcode */
        u1* code; /*!< Array com os códigos/opcodes */
        u4* position; /*!< Posição do opcode de interesse */
        ConstantPool cp;
};

/*!
   \brief Opcode com dois bytes de operandos.
   Os dois bytes são juntados para formarem um u2 por (byte1 << 8) | byte2.
 */
class U2OperandOpcode : public Opcode
{
public:
    virtual std::string getString();
    U2OperandOpcode(std::string);
};

class U2OperandOpcodeCP : public Opcode
{
public:
    virtual std::string getString();
    U2OperandOpcodeCP(std::string);
};

/*!
   \brief Opcode com dois bytes de operandos com sinal.
   Os dois bytes são juntados para formarem um inteiro de dois bytes com
   sinal por (byte1 << 8) | byte2.
 */
class S2OperandOpcode : public Opcode
{
public:
    virtual std::string getString();
    S2OperandOpcode(std::string);
};

/*!
   \brief Opcode com um byte de operando.
 */
class U1OperandOpcode : public Opcode
{
public:
    virtual std::string getString();
    U1OperandOpcode(std::string);
};

class U1OperandOpcodeCP : public Opcode
{
public:
    virtual std::string getString();
    U1OperandOpcodeCP(std::string);
};


/*!
   \brief Opcode de incremento.
 */
class IncrementOpcode : public Opcode
{
public:
    virtual std::string getString();
    IncrementOpcode(std::string);
};

/*!
   \brief Classe que reúne todos os opcodes.
 */
class Opcodes
{
public:

    /*!
       \return O objeto singleton da classe.
     */
    static Opcodes& getInstance();

    /*!
       \brief Retorna a string de um opcode.
       
       \param code Array que contêm os opcodes.
       \param position Posição do opcode desejado no array.
       \return std::string String que representa a forma textual de um opcode.
     */
    static std::string getString(u1 code[], u4& position, ConstantPool cp);

    /*!
       \brief Imprime na tela os opcodes em um array de opcodes.
       
       \param out Stream de saída.
       \param code Array com os opcodes.
       \param codeLength Comprimento do array de opcodes.
     */
    static void printCode(std::ostream& out, ConstantPool cp, u1 code[], u4 codeLength);

private:

    /*!
       \brief Constrói um novo objeto Opcodes.
     */
    Opcodes();

    /*!
       \brief Destrói um objeto Opcodes.
     */
    ~Opcodes();

    std::vector<Opcode*> opcodes; /*!< Vetor com os valores de opcodes. */

public:

    /* Como a classe implementa o padrão Singleton, os métodos seguintes foram
       deletados para evitar uma nova instância fora o single do objeto */
    Opcodes(const Opcodes&) = delete;
    void operator=(Opcodes const&) = delete;

};

#endif // _OPCODE_H_