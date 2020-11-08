#ifndef UTILS_H
#define UTILS_H

#include "Definitions.h"
#include <string.h>
#include <assert.h>

	/*!
    \brief Junta os bytes mais significativos com os bytes menos significatos.
    Retorna  ((uint64_t) #highBytes << 32) + #lowBytes.
	\param highBytes Bytes mais significativos do valor numérico (Big-endian)
	\param lowBytes Bytes menos significativos do valor numérico (Big-endian)
    \return Valor do tipo uint64_t
    */
	u8 highlowBytes(u4 highBytes, u4 lowBytes);

	/*!
    \brief Decodifica o valor \a float dos bytes dados à função.
    Realiza-se um cast de forma a obter o valor do tipo \a float sem modificar os bytes.
	\param bytes Bytes do valor numérico
    \return valor \a float decodificado
    */
	float getFloat(u4 bytes);
	/*!
    \brief Decodifica o valor \a long dos bytes dados à função.
    O valor será dado por ((uint64_t) #highBytes << 32) + #lowBytes.
	A função então realiza um cast de forma a obter o valor do tipo \a long sem modificar os bytes.
	\param highBytes Bytes mais significativos do valor numérico (Big-endian)
	\param lowBytes Bytes menos significativos do valor numérico (Big-endian)
    \return valor \a long decodificado
    */
	long getLong(u4 highBytes, u4 lowBytes);
	/*!
    \brief Decodifica o valor \a double dos bytes dados à função.
    Os bytes highBytes e highBytes são primeiro convertidos em \a long. 
	Realiza-se um cast de forma a obter o valor do tipo \a double sem modificar os bytes.
	\param highBytes Bytes mais significativos do valor numérico (Big-endian) de ponto flutuante IEEE 754.
	\param lowBytes Bytes menos significativos do valor numérico (Big-endian) de ponto flutuante IEEE 754.
    \return valor \a double decodificado
    */
	double getDouble(u4 highBytes, u4 lowBytes);

	/*!
    \brief Decodifica o valor \a int dos bytes dados à função.
    O valor \a int será dado por (int) bytes
	\param bytes Bytes do valor numérico
    \return valor \a int decodificado
    */
	int getInt(u4 bytes);

	/*!
    \brief Decodifica o valor \a bool dos bytes dados à função.
    O valor \a int será dado por (bool) bytes
	\param bytes Bytes do valor numérico
    \return valor \a bool decodificado
    */
	bool getBool(u4 bytes);

    /**
     * @brief Converte u4 em short som sinal.
     * 
     * @param bytes Bytes a serem convertidos.
     * @return short O valor convertido.
     */
    short getShort(u4 bytes);

    /**
     * @brief Converte u4 em byte com sinal.
     * 
     * @param bytes Bytes a serem convertidos.
     * @return int8_t Byte com sinal convertido.
     */
    int8_t getByte(u4 bytes);

    /**
     * @brief Converte um u4 em char.
     * 
     * @param bytes Bytes a serem convertidos.
     * @return char Char convertido.
     */
    char getChar(u4 bytes);

    /**
     * @brief Junta os dois bytes como um único índice.
     * 
     * @param byte1 Primeiro byte.
     * @param byte2 Segundo byte.
     * @return u2 O índice criado.
     */
    u2 getIndex(u1 byte1, u1 byte2);

    /**
     * @brief Cria um offset com sinal a parir de dois bytes.
     * 
     * @param high Byte MSB.
     * @param low Byte LSB.
     * @return int16_t Offset resultante.
     */
    int16_t getBranchOffset(u1 high, u1 low);

    /**
     * @brief Transforma um ponteiro de bytes em um u8.
     * Transforma a posição apontada.
     * 
     * @return u8 O valor do ponteiro em bytes.
     */
    u8 charPointerToU8(u1*);

    /**
     * @brief Pega um conjunto de 8 bytes e o transforma em ponteiro.
     * 
     * @return char* O ponteiro criado.
     */
    char* u8ToCharPointer(u4, u4);

    
	#endif // UTILS_H_