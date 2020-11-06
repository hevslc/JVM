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
    u4 getHighd(double d);
    u4 getLowd(double d);

    SlotType type;
    u4 value;
};

#endif