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

//! Método reading
/*!
	Método lê todo o conteúdo do arquivo .class armazenando as informações 
	no objeto da classe ClassFile em seus respectivos atributos.
	\param f Arquivo .class a ser lido.
	\sa ClassFile::rconstantPoolt(std::ifstream&)
*/ 
void ClassFile::reading(std::ifstream& f){
	magic = r4(f);					//leitura de magic
	minorVersion = r2(f);				//leitura de minor version
	majorVersion = r2(f);				//leitura de major version
	constantPoolCount = r2(f);		//leitura de constant pool count
	constantPool = ConstantPoolT(f, constantPoolCount);
	acess_flags = r2(f);
	this_class = r2(f);
	super_class = r2(f);
	interfaces_count = r2(f);
}




//_______ DECODING
void ClassFile::racessFlags(u2 mask){
	for(auto p=acessFlags.begin(); p!=acessFlags.end(); ++p)
		p->second = ((p->first & mask)==p->first);	
}