#include "Interface.h"

//! Método Interfaces
/*!
	Método lê de 2 em 2 bytes do arquivo na forma big-endian, contabilizando o número
    de interfaces e adicionando elas no fim do vector. 
	\param f Arquivo .class a ser lido.
	\param interfacesCount Número de interfaces no arquivo.
*/ 

Interfaces::Interfaces(std::ifstream& f, u2 interfacesCount){
    for(int i=0; i<interfacesCount; i++){
        push_back(r2(f));
    }
}


//! Método print
/*!
	Método para imprimir o campo Interfaces.
	\param cpt Variável instanciada do constant pool para acessar os métodos
    \param out Ponteiro para variável de saída do sistema
*/ 
void Interfaces::print(ConstantPool cpt, std::ostream& out){
    if(size()){
        out << "\n__________________Interfaces____________________" << std::endl;
        out << std::showbase;
        for (auto idx : *this){
            out <<  "cp_info #" << idx << " " << cpt.getUtf8Class(idx-1) << std::endl;
        }
    }
}