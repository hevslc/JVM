#ifndef _OPCODE_H_
#define _OPCODE_H_

#include "Definitions.h"

enum class Opcode : u1
{
    ALOAD = 0x19,
    ALOAD_0 = 0x2A
};

class Opcodes
{
public:

    static Opcodes& getInstance();

    static std::string getString(u1 opcode);

    static void printCode(std::ostream& out, u1 code[], u4 codeLength);

private:
    Opcodes();

    std::vector<std::string> opcodes;

public:

    Opcodes(Opcodes const&) = delete;
    void operator=(Opcodes const&) = delete;

};

#endif // _OPCODE_H_