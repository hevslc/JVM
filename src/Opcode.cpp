#include "Opcode.h"

Opcodes::Opcodes():
opcodes(0xff + 1, "Not implemented")
{
    opcodes[0x2A] = "aload_0";
    opcodes[0x2B] = "aload_1";
    opcodes[0x2C] = "aload_2";
    opcodes[0x2D] = "aload_3";
    opcodes[0xB7] = "invokespecial";
}

Opcodes& Opcodes::getInstance()
{
    static Opcodes instance;
    return instance;
}

std::string Opcodes::getString(u1 opcode)
{
    try {
        return Opcodes::getInstance().opcodes.at(opcode);
    }
    catch (const std::out_of_range &e) {
        return "Opcode too large";
    }
}

void Opcodes::printCode(std::ostream& out, u1 code[], u4 codeLength)
{
    for (u4 i = 0; i < codeLength; i++)
    {
        out << Opcodes::getString(code[i]) << std::endl;
    }
}