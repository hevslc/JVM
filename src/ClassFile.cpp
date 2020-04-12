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
										 acessFlagsMask(r2(f)),
										 thisClassIdx(r2(f)),
										 superClassIdx(r2(f)),
										 interfacesCount(r2(f)),
										 //ler interfaces
										 fieldsCount(r2(f)),
										 fields(f, fieldsCount, constantPool),
										 methodsCount(r2(f)),
										 methods(f, methodsCount, constantPool),
										 attributesCount(r2(f)),
										 attributes(f, attributesCount, constantPool)
{
	version.put(majorVersion);
	acessFlags.set(acessFlagsMask);
	thisClass.get(thisClassIdx, constantPool.getUtf8Class(thisClassIdx-1));
	superClass.get(superClassIdx, constantPool.getUtf8Class(superClassIdx-1));
}


void ClassFile::print(u1 mode, std::string argv){
	if(mode == infile){
		mkdir("./Output", 0777);
		std::string name = "./Output/" + argv.substr(9, argv.size()-15) + ".txt";
		
		std::ofstream f;
	  	f.open(name);
	  	printBuf(f.rdbuf());
	  	f.close();
	}
	else if(mode == interminal)
		printBuf(std::cout.rdbuf());
}

void ClassFile::printBuf(std::streambuf  *buf){
	std::ostream out(buf);
	out << std::showbase;
	out << "Magic............: " << std::hex << magic << std::endl;
	out << "Minor Version....: " << std::hex << minorVersion << std::endl;
	out << "Major Version....: " << std::hex << majorVersion;
	out << "  [" << version.get() << "]" << std::endl;
	constantPool.print(out);
	acessFlags.print(out);
	thisClass.print(out);
	superClass.print(out);
	//Tables
	out << "ConstantPoolCount: " << std::dec << constantPoolCount << std::endl;
	out << "Interfaces Count.: " << std::dec << interfacesCount << std::endl;
}
