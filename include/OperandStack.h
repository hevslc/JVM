#ifndef OPERAND_STACK_H
#define OPERAND_STACK_H

#include <stack>  
#include "Slot.h"
#include "Utils.h"

class Operands : public std::stack<Slot>{
public:
	Operands() {}

	/*!
     \brief Pega o valor do slot, passa para float e retira da pilha.
   */
	float popFloat();

	/*!
     \brief Pega o valor do slot, passa para double e retira da pilha.
   */
	double popDouble();

	/*!
     \brief Pega o valor do slot, passa para long e retira da pilha.
   */
	long popLong();

	/*!
     \brief Pega o valor do slot, passa para int e retira da pilha.
   */
	int popInt();

	/*!
     \brief Pega o valor do slot, passa para bool e retira da pilha.
   */
	bool popBool();
	
	/*!
     \brief Insere um Long na pilha ocupando duas posições.
   */
	void pushLong(long l);

	/*!
     \brief Insere um double na pilha ocupando duas posições.
   */
	void pushDouble(double d);

	char* popString();

};

#endif //OPERAND_STACK_H