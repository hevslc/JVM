#include "Interface.h"

Interfaces::Interfaces(std::ifstream& f, u2 interfacesCount){
    for(int i=0; i<interfacesCount-1; i++){
        push_back(r2(f));
    }
}

void Interfaces::print(ConstantPool cpt, std::ostream& out){
    if(size()){
        out << "\n__________________Interfaces____________________" << std::endl;
        out << std::showbase;
        for (auto idx : *this){
            out <<  "cp_info #" << idx << " " << cpt.getUtf8Class(idx-1);
        }
    }
}



