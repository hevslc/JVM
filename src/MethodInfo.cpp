#include "MethodInfo.h"

Methods::Methods(std::ifstream& file):
std::vector<MethodInfo*>(readMethodsCount(file))
{
    ClassFile classFile;
    for (u2 i = 0; i < size(); i++)
    {
        at(i) = new MethodInfo();
        at(i)->accessFlags = classFile.r2(file);
        at(i)->nameIndex = classFile.r2(file);
        at(i)->descriptorIndex = classFile.r2(file);
        at(i)->attributesCount = classFile.r2(file);
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

void Methods::print() {
    for (auto method : *this)
    {
        std::cout << "AccessFlags: " << method->accessFlags << std::endl;
        std::cout << "Name index: " << method->nameIndex << std::endl;
        std::cout << "Descriptor index: " << method->descriptorIndex << std::endl;
        std::cout << "Attributes count: " << method->attributesCount << std::endl;
    }
}

u2 Methods::readMethodsCount(std::ifstream& file) {
    ClassFile classFile;
    u2 value = classFile.r2(file);
    std::cout << value << std::endl;
    return value;
}