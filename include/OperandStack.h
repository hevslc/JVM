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

	/**
	 * @brief Retira um short com sinal da pilha.
	 * Faz o pop do slot do topo.
	 * 
	 * @return short O valor short criado.
	 */
	short popShort();

	/**
	 * @brief Retira um byte com sinal da pilha.
	 * Faz o pop do topo..
	 * 
	 * @return int8_t O byte com sinal retornado.
	 */
	int8_t popByte();

	/**
	 * @brief Retira um char da pilha.
	 * Faz o pop do topo.
	 * 
	 * @return char 
	 */
	char popChar();
	
	/*!
     \brief Insere um Long na pilha ocupando duas posições.
   */
	void pushInt(int i);

	/*!
     \brief Insere um Long na pilha ocupando duas posições.
   */
	void pushLong(long l);

	/*!
     \brief Insere um double na pilha ocupando duas posições.
   */
	void pushFloat(float f);

	/*!
     \brief Insere um double na pilha ocupando duas posições.
   */
	void pushDouble(double d);

	/**
	 * @brief Retorna o topo da pilha como uma string.
	 * Faz pop do topo.
	 * 
	 * @return char* Ponteiro para a string em questão.
	 */
	char* popString();

	/**
	 * @brief insere um u8 genérico na pilha.
	 * 
	 */
	void pushU8(SlotType, u8);

};

#endif //OPERAND_STACK_H
