#include "Opcode.h"

/////////////////////////////////////////////////////////////////////////////
// Classes derivadas de Opcode
/////////////////////////////////////////////////////////////////////////////

Opcode::Opcode(std::string name):
name(name)
{
}

std::string Opcode::getString()
{
    return name;
}

U2OperandOpcode::U2OperandOpcode(std::string name):
Opcode(name)
{
    knowsCode = true;
}

std::string U2OperandOpcode::getString()
{
    if (code != nullptr)
    {
        u4 pos = *position;
        u2 result = (code[pos + 1] << 8) | code[pos + 2];
        *position += 2;
        return name + " " + std::to_string(result);
    }
    return "";
}

U1OperandOpcode::U1OperandOpcode(std::string name):
Opcode(name)
{
    knowsCode = true;
}

std::string U1OperandOpcode::getString()
{
    if (code != nullptr)
    {
        u4 pos = *position;
        *position += 1;
        return name + " " + std::to_string(code[pos + 1]);
    }
    return "";
}

IncrementOpcode::IncrementOpcode(std::string name):
Opcode(name)
{
    knowsCode = true;
}

std::string IncrementOpcode::getString()
{
    if (code != nullptr)
    {
        u4 pos = *position;
        *position += 2;
        return name + " " + std::to_string(code[pos + 1]) + " " + std::to_string(code[pos + 2]);
    }
    return "";
}


/////////////////////////////////////////////////////////////////////////////
// Classe Opcodes
/////////////////////////////////////////////////////////////////////////////

Opcodes::Opcodes():
opcodes(0xff + 1, nullptr)
{
    opcodes[0x00] = new Opcode("nop");
    opcodes[0x01] = new Opcode("aconst_null");
    opcodes[0x02] = new Opcode("iconst_m1");
    opcodes[0x03] = new Opcode("iconst_0");
    opcodes[0x04] = new Opcode("iconst_1");
    opcodes[0x05] = new Opcode("iconst_2");
    opcodes[0x06] = new Opcode("iconst_3");
    opcodes[0x07] = new Opcode("iconst_4");
    opcodes[0x08] = new Opcode("iconst_5");
    opcodes[0x09] = new Opcode("lconst_0");
    opcodes[0x0A] = new Opcode("lconst_1");
    opcodes[0x0B] = new Opcode("fconst_0");
    opcodes[0x0C] = new Opcode("fconst_1");
    opcodes[0x0D] = new Opcode("fconst_2");
    opcodes[0x0E] = new Opcode("dconst_0");
    opcodes[0x0F] = new Opcode("dconst_1");
    opcodes[0x10] = new U1OperandOpcode("bipush");
    opcodes[0x11] = new U2OperandOpcode("sipush");
    opcodes[0x12] = new U1OperandOpcode("ldc");
    opcodes[0x13] = new U2OperandOpcode("ldc_w");
    opcodes[0x14] = new U2OperandOpcode("ldc2_w");
    opcodes[0x15] = new U1OperandOpcode("iload");
    opcodes[0x16] = new U1OperandOpcode("lload");
    opcodes[0x17] = new U1OperandOpcode("fload");
    opcodes[0x18] = new U1OperandOpcode("dload");
    opcodes[0x19] = new U1OperandOpcode("aload");
    opcodes[0x1A] = new Opcode("iload_0");
    opcodes[0x1B] = new Opcode("iload_1");
    opcodes[0x1C] = new Opcode("iload_2");
    opcodes[0x1D] = new Opcode("iload_3");
    opcodes[0x1E] = new Opcode("lload_0");
    opcodes[0x1F] = new Opcode("lload_1");
    opcodes[0x20] = new Opcode("lload_2");
    opcodes[0x21] = new Opcode("lload_3");
    opcodes[0x22] = new Opcode("fload_0");
    opcodes[0x23] = new Opcode("fload_1");
    opcodes[0x24] = new Opcode("fload_2");
    opcodes[0x25] = new Opcode("fload_3");
    opcodes[0x26] = new Opcode("dload_0");
    opcodes[0x27] = new Opcode("dload_1");
    opcodes[0x28] = new Opcode("dload_2");
    opcodes[0x29] = new Opcode("dload_3");
    opcodes[0x2A] = new Opcode("aload_0");
    opcodes[0x2B] = new Opcode("aload_1");
    opcodes[0x2C] = new Opcode("aload_2");
    opcodes[0x2D] = new Opcode("aload_3");
    opcodes[0x2E] = new Opcode("iaload");
    opcodes[0x2F] = new Opcode("laload");
    opcodes[0x30] = new Opcode("faload");
    opcodes[0x31] = new Opcode("daload");
    opcodes[0x32] = new Opcode("aaload");
    opcodes[0x33] = new Opcode("baload");
    opcodes[0x34] = new Opcode("caload");
    opcodes[0x35] = new Opcode("saload");
    opcodes[0x36] = new U1OperandOpcode("istore");
    opcodes[0x37] = new U1OperandOpcode("lstore");
    opcodes[0x38] = new U1OperandOpcode("fstore");
    opcodes[0x39] = new U1OperandOpcode("dstore");
    opcodes[0x3A] = new U1OperandOpcode("astore");
    opcodes[0x3B] = new Opcode("istore_0");
    opcodes[0x3C] = new Opcode("istore_1");
    opcodes[0x3D] = new Opcode("istore_2");
    opcodes[0x3E] = new Opcode("istore_3");
    opcodes[0x3F] = new Opcode("lstore_0");
    opcodes[0x40] = new Opcode("lstore_1");
    opcodes[0x41] = new Opcode("lstore_2");
    opcodes[0x42] = new Opcode("lstore_3");
    opcodes[0x43] = new Opcode("fstore_0");
    opcodes[0x44] = new Opcode("fstore_1");
    opcodes[0x45] = new Opcode("fstore_2");
    opcodes[0x46] = new Opcode("fstore_3");
    opcodes[0x47] = new Opcode("dstore_0");
    opcodes[0x48] = new Opcode("dstore_1");
    opcodes[0x49] = new Opcode("dstore_2");
    opcodes[0x4A] = new Opcode("dstore_3");
    opcodes[0x4B] = new Opcode("astore_0");
    opcodes[0x4C] = new Opcode("astore_1");
    opcodes[0x4D] = new Opcode("astore_2");
    opcodes[0x4E] = new Opcode("astore_3");
    opcodes[0x4F] = new Opcode("iastore");
    opcodes[0x50] = new Opcode("lastore");
    opcodes[0x51] = new Opcode("fastore");
    opcodes[0x52] = new Opcode("dastore");
    opcodes[0x53] = new Opcode("aastore");
    opcodes[0x54] = new Opcode("bastore");
    opcodes[0x55] = new Opcode("castore");
    opcodes[0x56] = new Opcode("sastore");
    opcodes[0x57] = new Opcode("pop");
    opcodes[0x58] = new Opcode("pop2");
    opcodes[0x59] = new Opcode("dup");
    opcodes[0x5A] = new Opcode("dup_x1");
    opcodes[0x5B] = new Opcode("dup_x2");
    opcodes[0x5C] = new Opcode("dup2");
    opcodes[0x5D] = new Opcode("dup2_x1");
    opcodes[0x5E] = new Opcode("dup2_x2");
    opcodes[0x5F] = new Opcode("swap");
    opcodes[0x60] = new Opcode("iadd");
    opcodes[0x61] = new Opcode("ladd");
    opcodes[0x62] = new Opcode("fadd");
    opcodes[0x63] = new Opcode("dadd");
    opcodes[0x64] = new Opcode("isub");
    opcodes[0x65] = new Opcode("lsub");
    opcodes[0x66] = new Opcode("fsub");
    opcodes[0x67] = new Opcode("dsub");
    opcodes[0x68] = new Opcode("imul");
    opcodes[0x69] = new Opcode("lmul");
    opcodes[0x6A] = new Opcode("fmul");
    opcodes[0x6B] = new Opcode("dmul");
    opcodes[0x6C] = new Opcode("idiv");
    opcodes[0x6D] = new Opcode("ldiv");
    opcodes[0x6E] = new Opcode("fdiv");
    opcodes[0x6F] = new Opcode("ddiv");
    opcodes[0x70] = new Opcode("irem");
    opcodes[0x71] = new Opcode("lrem");
    opcodes[0x72] = new Opcode("frem");
    opcodes[0x73] = new Opcode("drem");
    opcodes[0x74] = new Opcode("ineg");
    opcodes[0x75] = new Opcode("lneg");
    opcodes[0x76] = new Opcode("fneg");
    opcodes[0x77] = new Opcode("dneg");
    opcodes[0x78] = new Opcode("ishl");
    opcodes[0x79] = new Opcode("lshl");
    opcodes[0x7A] = new Opcode("ishr");
    opcodes[0x7B] = new Opcode("lshr");
    opcodes[0x7C] = new Opcode("iushr");
    opcodes[0x7D] = new Opcode("lushr");
    opcodes[0x7E] = new Opcode("iand");
    opcodes[0x7F] = new Opcode("land");
    opcodes[0x80] = new Opcode("ior");
    opcodes[0x81] = new Opcode("lor");
    opcodes[0x82] = new Opcode("ixor");
    opcodes[0x83] = new Opcode("lxor");
    opcodes[0x84] = new IncrementOpcode("iinc");
    opcodes[0x85] = new Opcode("i2l");
    opcodes[0x86] = new Opcode("i2f");
    opcodes[0x87] = new Opcode("i2d");
    opcodes[0x88] = new Opcode("l2i");
    opcodes[0x89] = new Opcode("l2f");
    opcodes[0x8A] = new Opcode("l2d");
    opcodes[0x8B] = new Opcode("f2i");
    opcodes[0x8C] = new Opcode("f2l");
    opcodes[0x8D] = new Opcode("f2d");
    opcodes[0x8E] = new Opcode("d2i");
    opcodes[0x8F] = new Opcode("d2l");
    opcodes[0x90] = new Opcode("d2f");
    opcodes[0x91] = new Opcode("i2b");
    opcodes[0x92] = new Opcode("i2c");
    opcodes[0x93] = new Opcode("i2s");
    opcodes[0x94] = new Opcode("lcmp");
    opcodes[0x95] = new Opcode("fcmpl");
    opcodes[0x96] = new Opcode("fcmpg");
    opcodes[0x97] = new Opcode("dcmpl");
    opcodes[0x98] = new Opcode("dcmpg");
    opcodes[0x99] = new U2OperandOpcode("ifeq");
    opcodes[0x9A] = new U2OperandOpcode("ifne");
    opcodes[0x9B] = new U2OperandOpcode("iflt");
    opcodes[0x9C] = new U2OperandOpcode("ifge");
    opcodes[0x9D] = new U2OperandOpcode("ifgt");
    opcodes[0x9E] = new U2OperandOpcode("ifle");
    opcodes[0x9F] = new U2OperandOpcode("if_icmpeq");
    opcodes[0xA0] = new U2OperandOpcode("if_icmpne");
    opcodes[0xA1] = new U2OperandOpcode("if_icmplt");
    opcodes[0xA2] = new U2OperandOpcode("if_icmpge");
    opcodes[0xA3] = new U2OperandOpcode("if_icmpgt");
    opcodes[0xA4] = new U2OperandOpcode("if_icmple");
    opcodes[0xA5] = new U2OperandOpcode("if_acmpeq");
    opcodes[0xA6] = new U2OperandOpcode("if_acmpne");
    opcodes[0xA7] = new U2OperandOpcode("goto");
    opcodes[0xA8] = new U2OperandOpcode("jsr");
    opcodes[0xA9] = new U1OperandOpcode("ret");
    // TODO tableswitch 0xAA
    // TODO lookupswitch 0xAB
    opcodes[0xAC] = new Opcode("ireturn");
    opcodes[0xAD] = new Opcode("lreturn");
    opcodes[0xAE] = new Opcode("freturn");
    opcodes[0xAF] = new Opcode("dreturn");
    opcodes[0xB0] = new Opcode("areturn");
    opcodes[0xB1] = new Opcode("return");
    opcodes[0xB2] = new U2OperandOpcode("getstatic");
    opcodes[0xB3] = new U2OperandOpcode("putstatic");
    opcodes[0xB4] = new U2OperandOpcode("getField");
    opcodes[0xB5] = new U2OperandOpcode("putfield");
    opcodes[0xB6] = new U2OperandOpcode("invokevirtual");
    opcodes[0xB7] = new U2OperandOpcode("invokeSpecial");
    opcodes[0xB8] = new U2OperandOpcode("invokestatic");
    // TODO invokeinterface 0xB9
    // TODO invokedynamic 0xBA
    opcodes[0xBB] = new U2OperandOpcode("new");
    opcodes[0xBC] = new U1OperandOpcode("newarray");
    opcodes[0xBD] = new U2OperandOpcode("anewarray");
    opcodes[0xBE] = new Opcode("arraylength");
    opcodes[0xBF] = new Opcode("athrow");
    opcodes[0xC0] = new U2OperandOpcode("checkcast");
    opcodes[0xC1] = new U2OperandOpcode("instanceof");
    opcodes[0xC2] = new Opcode("monitorenter");
    opcodes[0xC3] = new Opcode("monitorexit");
    // TODO wide 0xC4
    // TODO multianewarray 0xC5
    opcodes[0xC6] = new U2OperandOpcode("ifnull");
    opcodes[0xC7] = new U2OperandOpcode("ifnonnull");
    // TODO goto_w 0xC8
    // TODO jsr_w 0xC9
}

void Opcodes::clear()
{
    if (instance != nullptr)
    {
        delete instance;
    }
}

Opcodes::~Opcodes()
{
    for (Opcode* opcode : opcodes)
    {
        if (opcode != nullptr)
        {
            delete opcode;
        }
    }
}

Opcodes* Opcodes::instance;

Opcodes* Opcodes::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Opcodes();
    }
    return instance;
}

std::string Opcodes::getString(u1 code[], u4& position)
{
    try {
        Opcode* op = Opcodes::getInstance()->opcodes.at(code[position]);
        if (op != nullptr)
        {
            if (op->knowsCode)
            {
                op->injectCode(code, position);
            }
            return op->getString();            
        }
        return "Not Implemented";
    }
    catch (const std::out_of_range &e) {
        return "Opcode too large";
    }
}

void Opcodes::printCode(std::ostream& out, u1 code[], u4 codeLength)
{
    for (u4 i = 0; i < codeLength; i++)
    {
        out << Opcodes::getString(code, i) << std::endl;
    }
}