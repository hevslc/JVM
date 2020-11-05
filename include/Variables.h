#ifndef _VARIABLES_HPP_
#define _VARIABLES_HPP_

#include <vector>
#include "Slot.h"
#include "Utils.h"

class Variables : public std::vector<Slot>
{
public:
    Variables(){};

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
};

#endif