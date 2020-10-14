#include "Opcode.h"

#include "Definitions.h"
#include "CpInfo.h"
#include "AttributeInfo.h"
#include "FieldInfo.h"
#include "MethodInfo.h"

/**
 * Classes derivadas do OPCODE
 */

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

U2OperandOpcodeCP::U2OperandOpcodeCP(std::string name):
Opcode(name)
{
    knowsCode = true;
}

std::string U2OperandOpcodeCP::getString()
{
    if (code != nullptr)
    {
        u4 pos = *position;
        u2 result = (code[pos + 1] << 8) | code[pos + 2];
        *position += 2;

        return name + " " + std::to_string(result) + " <" 
        + cp.getUtf8Class(cp[result-1].Class.nameIndex-1) + "." 
        + cp.getNNameAndType(cp[result-1].FieldMethInter.nameTypeIndex-1) + ">";
    }
    return "";
}

U2OperandOpcodeCPNew::U2OperandOpcodeCPNew(std::string name):
Opcode(name)
{
    knowsCode = true;
}

std::string U2OperandOpcodeCPNew::getString()
{
    if (code != nullptr)
    {
        u4 pos = *position;
        u2 result = (code[pos + 1] << 8) | code[pos + 2];
        *position += 2;

        return name + " " + std::to_string(result) + " <" 
        + cp.getUtf8Str(cp[result-1].Class.nameIndex-1) + ">";
    }
    return "";
}

U2OperandOpcodeCPDouble::U2OperandOpcodeCPDouble(std::string name):
Opcode(name)
{
    knowsCode = true;
}

std::string U2OperandOpcodeCPDouble::getString()
{
    if (code != nullptr)
    {
        u4 pos = *position;
        u2 result = (code[pos + 1] << 8) | code[pos + 2];
        *position += 2;

        return name + " " + std::to_string(result) + " <" 
        + std::to_string(cp.getDouble(cp[result-1].Double.highBytes-1, cp[result-1].Double.lowBytes-1)) + ">";
    }
    return "";
}

S2OperandOpcode::S2OperandOpcode(std::string name):
Opcode(name)
{
    knowsCode = true;
}

std::string S2OperandOpcode::getString()
{
    if (code != nullptr)
    {
        u4 pos = *position;
        u2 result = (code[pos + 1] << 8) | code[pos + 2];
        *position += 2;
        return name + " " + std::to_string((int16_t) result);
    }
    return "";
}

S4OperandOpcode::S4OperandOpcode(std::string name):
Opcode(name)
{
    knowsCode = true;
}

std::string S4OperandOpcode::getString()
{
    if (code != nullptr)
    {
        u4 pos = *position;
        u2 result = (code[pos + 1] << 24) | (code[pos + 2] << 16) | 
        (code[pos + 3 << 8]) | code[pos + 4];
        *position += 4;
        return name + " " + std::to_string((int32_t) result);
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


U1OperandOpcodeCP::U1OperandOpcodeCP(std::string name):
Opcode(name)
{
    knowsCode = true;
}

std::string U1OperandOpcodeCP::getString()
{
    if (code != nullptr)
    {
        u4 pos = *position;
        u2 result = code[pos + 1];
        *position += 1;

        return name + " " + std::to_string(code[pos + 1]) + " <" 
        + cp.getUtf8Str(cp[result-1].String.stringIndex-1) + ">";
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
        return name + " " + std::to_string(code[pos + 1]) + " " + std::to_string((int8_t)code[pos + 2]);
    }
    return "";
}

ModifyOpcode::ModifyOpcode(std::string name):
Opcode(name)
{
    knowsCode = true;
}

std::string ModifyOpcode::getString()
{
    if (code != nullptr)
    {
        u4 pos = *position;
        u2 result = (code[pos + 1] << 8) | code[pos + 2];
        
        if (code[pos] == 0x84) {
            u2 constant = (code[pos + 3] << 8) | code[pos + 4];
            *position += 4;
            return name + " " + std::to_string(result) + 
            std::to_string((int16_t) constant);
        }
        *position += 2;
        return name + " " + std::to_string(result);
    }
}


LookupswitchOpcode::LookupswitchOpcode(std::string name):
Opcode(name)
{
    knowsCode = true;
}

std::string LookupswitchOpcode::getString()
{
    if (code != nullptr) 
    {
        u4 pos = *position;
        u1 paddingbytes = (3 - (pos % 4));

        pos += paddingbytes;
        
        std::string out;

        int32_t defaultbyte = (code[pos + 1] << 24) | (code[pos + 2] << 16)
        | (code[pos + 3] << 8) | code[pos + 4];

        uint32_t npairs = (code[pos + 5] << 24) | (code[pos + 6] << 16)
        | (code[pos + 7] << 8) | code[pos + 8];

        out = name + " " + std::to_string(npairs);
        
        // Incremento "padding" de
        pos += 8;

        // Crio minhas 2 variáveis para guardar os matchs de npairs (case n e o offset desse case)
        int32_t intbytePair;
        uint32_t offsetbytePair;

        //for para percorrer todos os matchs do switch e construir a string de saída "out"
        for (int i = 0; i < npairs; i++)
        {
            int32_t intbytePair = (code[pos + 1] << 24) | (code[pos + 2] << 16) | (code[pos + 3] << 8) | code[pos + 4];
            uint32_t offsetbytePair = (code[pos + 5] << 24) | (code[pos + 6] << 16) | (code[pos + 7] << 8) | code[pos + 8];
            out += "\n\t" + std::to_string(intbytePair) + ":   " + std::to_string(*position + offsetbytePair) + " (+" + std::to_string(offsetbytePair) + ")";
            pos += 8;
        };
        
        out += "\n\tdefault:   " + std::to_string(*position + defaultbyte) +  + " (+" + std::to_string(defaultbyte) + ")";
        
        //*position += npairs * 8 + 4 + 4 + paddingbytes;
        *position = pos;

        return out;
    }
}

TableswitchOpcode::TableswitchOpcode(std::string name):
Opcode(name)
{
    knowsCode = true;
}

std::string TableswitchOpcode::getString()
{
    if (code != nullptr) 
    {
        u4 pos = *position;
        u1 paddingbytes = (3 - (pos % 4));

        pos += paddingbytes;
        
        std::string out;

        int32_t defaultbyte = (code[pos + 1] << 24) | (code[pos + 2] << 16)
        | (code[pos + 3] << 8) | code[pos + 4];

        int32_t lowbyte = (code[pos + 5] << 24) | (code[pos + 6] << 16)
        | (code[pos + 7] << 8) | code[pos + 8];

        int32_t highbyte = (code[pos + 9] << 24) | (code[pos + 10] << 16)
        | (code[pos + 11] << 8) | code[pos + 12];

        out = name + " " + std::to_string(lowbyte) + " to " + std::to_string(highbyte);
        out += "\n\tdefault:   " + std::to_string(*position + defaultbyte) +  + " (+" + std::to_string(defaultbyte) + ")"; 

        *position = pos + 12 + (highbyte-lowbyte+1)*4;
        //*position += 32;
        return out;
    }
}

/////////////////////////////////////////////////////////////////////////////
// Classe Opcodes                                                          //
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
    opcodes[0x12] = new U1OperandOpcodeCP("ldc");
    opcodes[0x13] = new U2OperandOpcodeCP("ldc_w");
    opcodes[0x14] = new U2OperandOpcodeCPDouble("ldc2_w");
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
    opcodes[0x99] = new S2OperandOpcode("ifeq");
    opcodes[0x9A] = new S2OperandOpcode("ifne");
    opcodes[0x9B] = new S2OperandOpcode("iflt");
    opcodes[0x9C] = new S2OperandOpcode("ifge");
    opcodes[0x9D] = new S2OperandOpcode("ifgt");
    opcodes[0x9E] = new S2OperandOpcode("ifle");
    opcodes[0x9F] = new S2OperandOpcode("if_icmpeq");
    opcodes[0xA0] = new S2OperandOpcode("if_icmpne");
    opcodes[0xA1] = new S2OperandOpcode("if_icmplt");
    opcodes[0xA2] = new S2OperandOpcode("if_icmpge");
    opcodes[0xA3] = new S2OperandOpcode("if_icmpgt");
    opcodes[0xA4] = new S2OperandOpcode("if_icmple");
    opcodes[0xA5] = new S2OperandOpcode("if_acmpeq");
    opcodes[0xA6] = new S2OperandOpcode("if_acmpne");
    opcodes[0xA7] = new S2OperandOpcode("goto");
    opcodes[0xA8] = new S2OperandOpcode("jsr");
    opcodes[0xA9] = new U1OperandOpcode("ret");
    opcodes[0xAA] = new TableswitchOpcode("tableswitch");
    opcodes[0xAB] = new LookupswitchOpcode("lookupswitch");
    opcodes[0xAC] = new Opcode("ireturn");
    opcodes[0xAD] = new Opcode("lreturn");
    opcodes[0xAE] = new Opcode("freturn");
    opcodes[0xAF] = new Opcode("dreturn");
    opcodes[0xB0] = new Opcode("areturn");
    opcodes[0xB1] = new Opcode("return");
    opcodes[0xB2] = new U2OperandOpcodeCP("getstatic");
    opcodes[0xB3] = new U2OperandOpcodeCP("putstatic");
    opcodes[0xB4] = new U2OperandOpcodeCP("getField");
    opcodes[0xB5] = new U2OperandOpcodeCP("putfield");
    opcodes[0xB6] = new U2OperandOpcodeCP("invokevirtual");
    opcodes[0xB7] = new U2OperandOpcodeCP("invokeSpecial");
    opcodes[0xB8] = new U2OperandOpcodeCP("invokestatic");
    // TODO invokeinterface 0xB9 Rodrigo
    // TODO invokedynamic 0xBA Rodrigo
    opcodes[0xBB] = new U2OperandOpcodeCPNew("new");
    opcodes[0xBC] = new U1OperandOpcode("newarray");
    opcodes[0xBD] = new U2OperandOpcodeCPNew("anewarray");
    opcodes[0xBE] = new Opcode("arraylength");
    opcodes[0xBF] = new Opcode("athrow");
    opcodes[0xC0] = new U2OperandOpcodeCPNew("checkcast");
    opcodes[0xC1] = new U2OperandOpcodeCP("instanceof");
    opcodes[0xC2] = new Opcode("monitorenter");
    opcodes[0xC3] = new Opcode("monitorexit");
    opcodes[0xC4] = new ModifyOpcode("wide");
    // TODO multianewarray 0xC5 Rodrigo
    opcodes[0xC6] = new U2OperandOpcode("ifnull");
    opcodes[0xC7] = new U2OperandOpcode("ifnonnull");
    opcodes[0xC8] = new S4OperandOpcode("goto_w");
    opcodes[0xC9] = new S4OperandOpcode("jsr_w");
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

Opcodes& Opcodes::getInstance()
{
    static Opcodes instance;
    return instance;
}

std::string Opcodes::getString(u1 code[], u4 &position, ConstantPool cp)
{
    try
    {
        Opcode *op = Opcodes::getInstance().opcodes.at(code[position]);
        if (op != nullptr)
        {
            if (op->knowsCode)
            {
                op->injectCode(code, position, cp);
            }
            return op->getString();
        }
        return "Not Implemented";
    }
    catch (const std::out_of_range &e)
    {
        return "Opcode too large";
    }
}

void Opcodes::printCode(std::ostream& out, ConstantPool cp, u1 code[], u4 codeLength)
{
    for (u4 i = 0; i < codeLength; i++)
    {
        out << Opcodes::getString(code, i, cp) << std::endl;
    }
}