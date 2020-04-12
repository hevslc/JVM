#include "MethodInfo.h"

Methods::Methods(std::ifstream& file, u2 fieldsCount, ConstantPool cpTable):
std::vector<MethodInfo*>(fieldsCount)
{  
    for (u2 i = 0; i < size(); i++)
    {
        at(i) = new MethodInfo();
        at(i)->accessFlags = r2(file);
        at(i)->nameIndex = r2(file);
        at(i)->descriptorIndex = r2(file);
        at(i)->attributesCount = r2(file);
           at(i)->attributes = new Attributes(file, at(i)->attributesCount, cpTable);
    }
}

Methods::~Methods()
{
    for (auto method : *this)
    {
        if (method != nullptr)
        {
            delete method;
        }
    }
}

MethodInfo::~MethodInfo()
{
    if (attributes != nullptr)
    {
        delete attributes;
    }
}

void Methods::print(ConstantPool cpt) {
    if (size() > 0)
    {
        std::cout << std::endl
                  << "__________________ Methods __________________" << std::endl;
    }
    for (auto method : *this)
    {
        // TODO Melhorar a impressão com dados mais legíveis
        std::cout << "................................................." << std::endl;
        std::cout << "AccessFlags......: " << method->accessFlags << std::endl;
        std::cout << "Name index.......: " << method->nameIndex << std::endl;
        std::cout << "Descriptor index.: " << method->descriptorIndex << std::endl;
        std::cout << "Attributes count.: " << method->attributesCount << std::endl;
        //method->attributes->print(cpt);
        (void)cpt; //coloquei só pra não dar warning pela falta de uso de cpt
    }
}