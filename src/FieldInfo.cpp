#include "FieldInfo.h"

Fields::Fields(std::ifstream& f, u2 fieldsCount ,ConstantPool constantPool):
std::vector<FieldInfo*>(fieldsCount){ 
	for(u2 i = 0; i < size(); i++){
		at(i)= new FieldInfo();
		at(i)->accessFlags.set(r2(f));
		at(i)->nameIndex = r2(f);
		at(i)->descriptorIndex = r2(f);
		at(i)->attributesCount = r2(f);		
		at(i)->attributes = new Attributes(f, at(i)->attributesCount, constantPool);
		at(i)->init(constantPool);
	}
}

void FieldInfo::init(ConstantPool& cp)
{
    name = cp.getUtf8Str(nameIndex - 1);
    descriptor = cp.getUtf8Str(descriptorIndex - 1);
}

void FieldInfo::print(std::ostream& out, ConstantPool& cp)
{
    out << std::endl << ".................................................." << std::endl;
    out << "(Field)...............: ";
    accessFlags.print(out);
    printName(out);
    printDescriptor(out);
    out << "Attributes count.......: " << attributesCount << std::endl;
    out << "Attributes of " << name << ":" << std::endl;
    attributes->print(out, cp);
}

void FieldInfo::printName(std::ostream &out)
{
    out << "Name index.............: ";
    out << std::hex << nameIndex << " " + name << std::dec << std::endl;
}

void FieldInfo::printDescriptor(std::ostream &out)
{
    out << "Descriptor index.......: ";
    out << std::hex << descriptorIndex << " " + descriptor << std::dec << std::endl;
}

void Fields::print(std::ostream& out, ConstantPool cpt) {
    if (size() > 0)
    {
        out << std::endl
            << std::endl
            << "__________________ Fields __________________"
            << std::endl
            << std::endl;
    }
    for (auto field : *this)
    {
        field->print(out, cpt);
    }
}
