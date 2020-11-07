#ifndef _VARIABLES_HPP_
#define _VARIABLES_HPP_

#include <vector>
#include "Slot.h"
#include "Utils.h"

class Variables : public std::vector<Slot>
{
public:
    Variables(){};

    Variables(u1 size): std::vector<Slot>(size){};

    /*!
     \brief Pega o valor do slot, passa para float e retira do vetor.
   */
    float asFloat(int position);
    /*!
     \brief Pega o valor do slot, passa para double e retira do vetor.
   */
    double asDouble(int position);
    /*!
     \brief Pega o valor do slot, passa para inteiro e retira do vetor.
   */
    int asInt(int position);
    /*!
     \brief Pega o valor do slot, passa para long e retira do vetor.
   */
    long asLong(int position);
    /*!
     \brief Pega o valor do slot, passa para booleano e retira do vetor.
   */
    bool asBool(int position);
   /*!
     \brief Coloca um valor long no vetor, ocupando duas posições.
   */
    void putLong(long l, u1 position);
    /*!
     \brief Coloca um valor double no vetor, ocupando duas posições.
   */
    void putDouble(double d, u1 position);

    void putU8(SlotType type, u8 value, u1 position);
};

#endif