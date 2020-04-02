#include "CpInfo.h"


//! Método rconstantPool
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
ConstantPoolT::ConstantPoolT(std::ifstream& f, u2 constantPoolCount){
	for(int i=0; i<constantPoolCount-1; i++){
		Cpinfo *cpinfo = new Cpinfo;
		cpinfo->tag = r1(f);
		switch(cpinfo->tag){
			case CONSTANT_Class:
				cpinfo->Class.nameIndex = r2(f);
				break;
			case CONSTANT_Fieldref:
			case CONSTANT_Methodref:
			case CONSTANT_InterfaceMethodref:
				cpinfo->FieldMethInter.classIndex = r2(f);
				cpinfo->FieldMethInter.nameTypeIndex = r2(f);
				break;
			case CONSTANT_String:
				cpinfo->String.stringIndex = r2(f);
				break;
			case CONSTANT_Integer:
			case CONSTANT_Float:
				cpinfo->IntegerFloat.bytes = r4(f);
				break;
			case CONSTANT_Long:
			case CONSTANT_Double:
				cpinfo->LongDouble.highBytes = r4(f);
				cpinfo->LongDouble.lowBytes = r4(f);
				break;
			case CONSTANT_NameAndType:
				cpinfo->NameAndType.nameIndex = r2(f);
				cpinfo->NameAndType.descriptorIndex = r2(f);
				break;
			case CONSTANT_Utf8:
				cpinfo->Utf8.lenght = r2(f);
				cpinfo->Utf8.bytes = new u1[cpinfo->Utf8.lenght];
				for(int j=0; j<cpinfo->Utf8.lenght; j++) cpinfo->Utf8.bytes[j] = r1(f);
				break;
			default:
				break;
		}
		push_back(*cpinfo);
	}
}

// PARA TESTE
void ConstantPoolT::printConstantPool(){
	for(auto cp=begin(); cp!=end(); cp++){
		std::cout << "tag: "   << (int)(*cp).tag << std::endl;
		switch((*cp).tag){
			case CONSTANT_Class:
				std::cout << "nameIndex: "  << (*cp).Class.nameIndex << std::endl;
				break;
			case CONSTANT_Fieldref:
			case CONSTANT_Methodref:
			case CONSTANT_InterfaceMethodref:
				std::cout << "classIndex: "  << (*cp).FieldMethInter.classIndex << std::endl;
				std::cout << "nameTypeIndex: "  << (*cp).FieldMethInter.nameTypeIndex << std::endl;
				break;
			case CONSTANT_String:
				std::cout << "stringIndex: "  << (*cp).String.stringIndex << std::endl;
				break;
			case CONSTANT_Integer:
			case CONSTANT_Float:
				std::cout << "bytes: "  << (*cp).IntegerFloat.bytes << std::endl;
				break;
			case CONSTANT_Long:
			case CONSTANT_Double:
				std::cout << "highBytes: "  << (*cp).LongDouble.highBytes << std::endl;
				std::cout << "lowBytes: "  << (*cp).LongDouble.lowBytes << std::endl;
				break;
			case CONSTANT_NameAndType:
				std::cout << "nameIndex: "  << (*cp).NameAndType.nameIndex << std::endl;
				std::cout << "descriptorIndex: "  << (*cp).NameAndType.descriptorIndex << std::endl;
				break;
			case CONSTANT_Utf8:
				std::cout << "lenght: "  << (*cp).Utf8.lenght << std::endl;
				for(int j=0; j<(*cp).Utf8.lenght; j++) 
					std::cout << (*cp).Utf8.bytes[j];
				std::cout << std::endl;
				break;
			default:
				break;
		}
	}
}