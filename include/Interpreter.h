#ifndef _Interpreter_H_
#define _Interpreter_H_

#include "ClassFile.h"
#include "Instructions.h"

/**
 * @brief Classe do Interpretador
 * Contém a classFile lido e vetor de instruções.
 * Irá interpretar e executar um .class
 */
class Interpreter{
public:
    ClassFile        classFile;     /*!< .class lido */
    Instructions     instruction;  /*!< vetor de instruções */

    Interpreter() {};
    //! Construtor
    /*!
    \param bytecode bytes da instrução
    \sa Operands, Variables
    */ 
    Interpreter(ClassFile classFile);

    void execute();
    
};

#endif