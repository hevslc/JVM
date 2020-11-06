#ifndef UTILS_H
#define UTILS_H

#include "Definitions.h"

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

    u2 getIndex(u1 byte1, u1 byte2);

	#endif // UTILS_H_