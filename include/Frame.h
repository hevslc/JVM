#ifndef _Frame_H_
#define _Frame_H_

#include "Definitions.h"
#include "OperandStack.h"

/**
 * @brief Define um frame
 * Contém pilha de operandos, pilha de variáveis locais, PC, 
 * valor de retorno e bytes da instrução
 */
class Frame{
public:
    Operands        operands;     /*!< Pilha de operandos */
    //Variables       variables;  /*!< Vetor de variáveis locais */
    u4              PC=0;         /*!< Contador de Programa PC */
    u4              returnResult; /*!< valor de retorno de uma método (instrução) */
    u1*             bytecode;     /*!< bytes da instrução */

    Frame() {}
    //! Construtor
    /*!
    \param bytecode bytes da instrução
    \sa Operands, Variables
    */ 
    Frame(u1* bytecode) : bytecode(bytecode) {};

    
};

#endif