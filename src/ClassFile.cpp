#include "ClassFile.h"


//! Método r1
/*!
	Método lê 1 byte do arquivo
	\param f Arquivo .class a ser lido.
	\return b Byte lido.
	\sa ::u1
*/ 
u1 ClassFile::r1(std::ifstream& f){
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
u2 ClassFile::r2(std::ifstream& f){
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
u4 ClassFile::r4(std::ifstream& f){
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
	this->magic = r4(f);					//leitura de magic
	this->minorVersion = r2(f);				//leitura de minor version
	this->majorVersion = r2(f);				//leitura de major version
	this->constantPoolCount = r2(f);		//leitura de constant pool count
	this->rconstantPoolt(f);				//leitura de constant pool table
}

//! Método rconstantPoolt
/*!
	Método lê toda a tabela de constantes do arquivo .class armazenando as informações 
	no objeto da classe cpinfo em seus respectivos atributos.
	Na cada estrutura lida é da forma 
	~~~~~{.cpp}
	cp_info {
	u1 tag;
	u1 info[ ];
	}
	~~~~~
	Portanto, a tribuição dos atributos é feita verificando a tag, o qual 
	define o tipo da informação em cp_info.
	\param f Arquivo .class a ser lido.
	\sa #CONSTANT_Class, #CONSTANT_Fieldref, #CONSTANT_Methodref, #CONSTANT_InterfaceMethodref,
		#CONSTANT_String, #CONSTANT_Integer, #CONSTANT_Float, #CONSTANT_Long, #CONSTANT_Double,
		#CONSTANT_NameAndType, #CONSTANT_Utf8
*/ 
void ClassFile::rconstantPoolt(std::ifstream& f){
	Cpinfo *cpinfo = new Cpinfo[this->constantPoolCount-1];
	for(int i=0; i<this->constantPoolCount-1; i++){
		cpinfo[i].tag = r1(f);
		switch(cpinfo[i].tag){
			case CONSTANT_Class:
				cpinfo[i].Class.nameIndex = r2(f);
				break;
			case CONSTANT_Fieldref:
			case CONSTANT_Methodref:
			case CONSTANT_InterfaceMethodref:
				cpinfo[i].FieldMethInter.classIndex = r2(f);
				cpinfo[i].FieldMethInter.nameTypeIndex = r2(f);
				break;
			case CONSTANT_String:
				cpinfo[i].String.stringIndex = r2(f);
				break;
			case CONSTANT_Integer:
			case CONSTANT_Float:
				cpinfo[i].IntegerFloat.bytes = r4(f);
				break;
			case CONSTANT_Long:
			case CONSTANT_Double:
				cpinfo[i].LongDouble.highBytes = r4(f);
				cpinfo[i].LongDouble.lowBytes = r4(f);
				break;
			case CONSTANT_NameAndType:
				cpinfo[i].NameAndType.nameIndex = r2(f);
				cpinfo[i].NameAndType.descriptorIndex = r2(f);
				break;
			case CONSTANT_Utf8:
				cpinfo[i].Utf8.lenght = r2(f);
				cpinfo[i].Utf8.bytes = new u1[cpinfo[i].Utf8.lenght];
				for(int j=0; j<cpinfo[i].Utf8.lenght; j++) cpinfo[i].Utf8.bytes[j] = r1(f);
				break;
			default:
				break;
		}
	}
	this->constantPool = new Cpinfo[this->constantPoolCount-1];
	this->constantPool = cpinfo;
}