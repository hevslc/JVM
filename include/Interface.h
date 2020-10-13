#ifndef INTERFACE_H
#define INTERFACE_H

#include "Definitions.h"
#include "CpInfo.h"

//! \class Interfaces
/*! 
   \brief Métodos para extração e impressão das interfaces do arquivo.
 */

class Interfaces : public std::vector<u2> {
public:
    Interfaces() {};
    Interfaces(std::ifstream& f, u2 interfacesCount);
    void print(ConstantPool cpt, std::ostream& out);
};



#endif