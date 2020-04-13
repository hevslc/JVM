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

void Methods::print(std::ostream& out, ConstantPool cpt) {
    if (size() > 0)
    {
        out << std::endl
                  << "__________________ Methods __________________" << std::endl;
    }
    for (auto method : *this)
    {
        // TODO Melhorar a impressão com dados mais legíveis
        out << ".............................................." << std::endl;
        out << "AccessFlags......: " << method->accessFlags << std::endl;
        out << "Name index.......: " << method->nameIndex << std::endl;
        out << "Descriptor index.: " << method->descriptorIndex << std::endl;
        out << "Attributes count.: " << method->attributesCount << std::endl;
        method->attributes->print(out, cpt);
    }
}