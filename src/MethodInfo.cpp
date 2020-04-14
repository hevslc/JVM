#include "MethodInfo.h"

Methods::Methods(std::ifstream& file, u2 fieldsCount, ConstantPool cpTable):
std::vector<MethodInfo*>(fieldsCount)
{  
    for (u2 i = 0; i < size(); i++)
    {
        at(i) = new MethodInfo();
        at(i)->accessFlags.set(r2(file));
        at(i)->nameIndex = r2(file);
        at(i)->descriptorIndex = r2(file);
        at(i)->attributesCount = r2(file);
        at(i)->attributes = new Attributes(file, at(i)->attributesCount, cpTable);
        at(i)->init(cpTable);
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

void MethodInfo::init(ConstantPool& cp)
{
    name = cp.getUtf8Str(nameIndex - 1);
    descriptor = cp.getUtf8Str(descriptorIndex - 1);
}

void MethodInfo::print(std::ostream& out, ConstantPool& cp)
{
    out << std::endl << ".................................................." << std::endl;
    out << "(Method)...............: ";
    accessFlags.print(out);
    printName(out);
    printDescriptor(out);
    out << "Attributes count.......: " << attributesCount << std::endl;
    out << "Attributes of " << name << ":" << std::endl;
    attributes->print(out, cp);
}

void MethodInfo::printName(std::ostream &out)
{
    out << "Name index.............: ";
    out << std::hex << nameIndex << " " + name << std::dec << std::endl;
}

void MethodInfo::printDescriptor(std::ostream &out)
{
    out << "Descriptor index.......: ";
    out << std::hex << descriptorIndex << " " + descriptor << std::dec << std::endl;
}

void Methods::print(std::ostream& out, ConstantPool cpt) {
    if (size() > 0)
    {
        out << std::endl
            << std::endl
            << "__________________ Methods __________________"
            << std::endl
            << std::endl;
    }
    for (auto method : *this)
    {
        method->print(out, cpt);
    }
}