#include "MethodInfo.h"

Methods::Methods(std::ifstream& file, ConstantPoolT cpTable):
std::vector<MethodInfo*>(readMethodsCount(file))
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

void Methods::print() {
    for (auto method : *this)
    {
        std::cout << "AccessFlags:      " << method->accessFlags << std::endl;
        std::cout << "Name index:       " << method->nameIndex << std::endl;
        std::cout << "Descriptor index: " << method->descriptorIndex << std::endl;
        std::cout << "Attributes count: " << method->attributesCount << std::endl;
    }
}

u2 Methods::readMethodsCount(std::ifstream& file) {
    return r2(file);
}