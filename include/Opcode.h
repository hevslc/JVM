#ifndef _OPCODE_H_
#define _OPCODE_H_

#include "Definitions.h"

class Opcode
{
    public:
        bool knowsCode = false;
        Opcode(std::string name);
        virtual ~Opcode() = default;
        virtual std::string getString();

        void inline injectCode(u1 code[], u4& position) {
            this->code = code;
            this->position = &position;
        }
    
    protected:
        std::string name;
        u1* code;
        u4* position;
};

/*!
   \brief Opcode com dois bytes de operandos.
   Os dois bytes são juntados para formarem um u2 por (byte1 << 8) | byte2.
 */
class U2OperandOpcode : public Opcode
{
public:
    virtual std::string getString();
    U2OperandOpcode(std::string);
};

/*!
   \brief Opcode com um byte de operando.
 */
class U1OperandOpcode : public Opcode
{
public:
    virtual std::string getString();
    U1OperandOpcode(std::string);
};

class IncrementOpcode : public Opcode
{
public:
    virtual std::string getString();
    IncrementOpcode(std::string);
};

class Opcodes
{
public:

    static Opcodes* getInstance();

    static void clear();

    static std::string getString(u1 code[], u4& position);

    static void printCode(std::ostream& out, u1 code[], u4 codeLength);

private:
    Opcodes();

    ~Opcodes();

    std::vector<Opcode*> opcodes;

    static Opcodes* instance;

public:

    Opcodes(Opcodes const&) = delete;
    void operator=(Opcodes const&) = delete;

};

#endif // _OPCODE_H_