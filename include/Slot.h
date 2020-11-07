#ifndef _SLOT_HPP_
#define _SLOT_HPP_

#include "Definitions.h"

/**
 * @brief Define o tipo de valor presente em um slot.
 */
enum class SlotType
{
    BOOL,
    BYTE,
    CHAR,
    INT,
    FLOAT,
    LONG,
    STRING_REF,
    REFERENCE,
    RETURN_ADDRESS,
    DOUBLE
};

/**
 * @brief Define um valor ou slot de uma coleção
 * É um slot da pilha de operandos ou do vetor de variáveis locais.
 */
class Slot
{
public:
    Slot() {}
    Slot(SlotType, u4);

    SlotType type;
    u4 value;
};

#endif
