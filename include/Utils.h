#ifndef UTILS_H
#define UTILS_H

#include "Definitions.h"

/*!
    \brief Decodifica o valor \a float dos bytes dados à função.
    A entrada bytes é do tipo int.  Então:
		- Se bytes é 0x7f800000, o valor \a float será infinito positivo.
		- Se bytes é 0xff800000, o valor \a float será infinito negativo.
		- Se bytes no intervalo [0x7f800001, 0x7fffffff] ou no intervalo [0xff800001, 0xffffffff], 
			então o valor \a float será NaN (not a number).
		- Em outros casos, seja \a s, \a e, e \a m três valores que são computados de \a bytes :
			-# int s = ((bytes >> 31) == 0) ? 1 : -1;
			-# int e = ((bytes >> 23) & 0xff);
			-# int m = (e == 0) ? (bytes & 0x7fffff) << 1 : (bytes & 0x7fffff) | 0x800000;
			Então o valor numérico será resultado da expressão matemática \f$ s \cdot m \cdot 2^{e-150} \f$.
	\param bytes Bytes do valor numérico
    \return valor \a float decodificado
    */
	float getFloat(u4 bytes);
	/*!
    \brief Decodifica o valor \a float dos bytes dados à função.
    O valor \a float será dado por ((long) #highBytes << 32) + #lowBytes
	\param highBytes Bytes mais significativos do valor numérico (Big-endian)
	\param lowBytes Bytes menos significativos do valor numérico (Big-endian)
    \return valor \a long decodificado
    */
	long getLong(u4 highBytes, u4 lowBytes);
	/*!
    \brief Decodifica o valor \a float dos bytes dados à função.
    Os bytes highBytes e highBytes são primeiro convertidos em \a long. Então:
		- Se bytes é 0x7ff0000000000000L, o valor \a double será infinito positivo.
		- Se bytes é 0xfff0000000000000L, o valor \a double será infinito negativo.
		- Se bytes no intervalo [0x7ff0000000000001L, 0x7fffffffffffffffL] 
			ou no intervalo [0xfff0000000000001L, 0xffffffffffffffffL], 
			então o valor \a double será NaN (not a number).
		- Em outros casos, seja \a s, \a e, e \a m três valores que são computados de \a bytes :
			-# int s = ((bytes >> 63) == 0) ? 1 : -1;
			-# int e = (int)((bytes >> 52) & 0x7ffL);
			-# long m = (e == 0) ? (bytes & 0xfffffffffffffL) << 1 : (bytes & 0xfffffffffffffL) | 0x10000000000000L;
			Então o valor numérico será resultado da expressão matemática \f$ s \cdot m \cdot 2^{e-1075} \f$.
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

	#endif // UTILS_H_