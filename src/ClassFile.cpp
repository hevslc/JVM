#include "ClassFile.h"


//! Método r1
/*!
	Método lê 1 byte do arquivo
	\param f Arquivo .class a ser lido.
	\return b Byte lido.
	\sa ::u1
*/ 
u1 r1(std::ifstream& f){
	u1 b;
	f.read((char *)&b, sizeof(u1));
	return b;
}

//! Método r2
/*!
	Método lê 2 bytes do arquivo na forma big-endian: Lê o primeiro byte atribuindo-o a 
	uma variável de 16 bits e desloca-o para os primeiros 8 bits (tornando-o mais significativo).
	Lê o segundo byte armazenando como menos significativo. Ou seja, b = byte1byte2.
	\param f Arquivo .class a ser lido.
	\return b 2 bytes lidos na ordem big-endian.
	\sa ::u2
*/ 
u2 r2(std::ifstream& f){
	u2 b = (u2)r1(f) << 8;
	b = b | (u2)r1(f);
	return b;
}

//! Método r4
/*!
	Método lê 4 bytes do arquivo na forma big-endian: Lê os bytes deslocando-os para direita
	para torná-los mais significativos. Ou seja, b = byte1byte2byte3byte4.
	\param f Arquivo .class a ser lido.
	\return b 4 bytes lidos na ordem big-endian.
	\sa ::u4
*/ 
u4 r4(std::ifstream& f){
	u4 b = (u4)r1(f) << 24;
	b = b | (u4)r1(f) << 16;
	b = b | (u4)r1(f) << 8;
	b = b | (u4)r1(f);
	return b;	
}

ClassFile::ClassFile(std::ifstream &f) : magic(r4(f)),
										 minorVersion(r2(f)),
										 majorVersion(r2(f)),
										 constantPoolCount(r2(f)),
										 constantPool(f, constantPoolCount),
										 acess_flags(r2(f)),
										 thisClass(r2(f)),
										 superClass(r2(f)),
										 interfacesCount(r2(f)),
										 //ler interfaces
										 fieldsCount(r2(f)),
										 fields(f, fieldsCount, constantPool),
										 methodsCount(r2(f)),
										 methods(f, methodsCount, constantPool)
{
}

//_______ DECODING
void ClassFile::racessFlags(u2 mask){
	for(auto p=acessFlags.begin(); p!=acessFlags.end(); ++p)
		p->second = ((p->first & mask)==p->first);	
}
