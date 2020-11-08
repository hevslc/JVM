#include "Instructions.h"


Instructions::Instructions(ClassFile* classFile){
    classes.push_back(classFile);
    instrs = {
        &Instructions::_nop,
        &Instructions::_aconst_null,
        &Instructions::_iconst_m1,
        &Instructions::_iconst_0,
        &Instructions::_iconst_1,
        &Instructions::_iconst_2,
        &Instructions::_iconst_3,
        &Instructions::_iconst_4,
        &Instructions::_iconst_5,
        &Instructions::_lconst_0,
        &Instructions::_lconst_1,
        &Instructions::_fconst_0,
        &Instructions::_fconst_1,
        &Instructions::_fconst_2,
        &Instructions::_dconst_0,
        &Instructions::_dconst_1,
        &Instructions::_bipush,
        &Instructions::_sipush,
        &Instructions::_ldc,
        &Instructions::_ldc_w,
        &Instructions::_ldc2_w,
        &Instructions::_iload,
        &Instructions::_lload,
        &Instructions::_fload,
        &Instructions::_dload,
        &Instructions::_aload,
        &Instructions::_iload_0,
        &Instructions::_iload_1,
        &Instructions::_iload_2,
        &Instructions::_iload_3,
        &Instructions::_lload_0,
        &Instructions::_lload_1,
        &Instructions::_lload_2,
        &Instructions::_lload_3,
        &Instructions::_fload_0,
        &Instructions::_fload_1,
        &Instructions::_fload_2,
        &Instructions::_fload_3,
        &Instructions::_dload_0,
        &Instructions::_dload_1,
        &Instructions::_dload_2,
        &Instructions::_dload_3,
        &Instructions::_aload_0,
        &Instructions::_aload_1,
        &Instructions::_aload_2,
        &Instructions::_aload_3,
        &Instructions::_iaload,
        &Instructions::_laload,
        &Instructions::_faload,
        &Instructions::_daload,
        &Instructions::_aaload,
        &Instructions::_baload,
        &Instructions::_caload,
        &Instructions::_saload,
        &Instructions::_istore,
        &Instructions::_lstore,
        &Instructions::_fstore,
        &Instructions::_dstore,
        &Instructions::_astore,
        &Instructions::_istore_0,
        &Instructions::_istore_1,
        &Instructions::_istore_2,
        &Instructions::_istore_3,
        &Instructions::_lstore_0,
        &Instructions::_lstore_1,
        &Instructions::_lstore_2,
        &Instructions::_lstore_3,
        &Instructions::_fstore_0,
        &Instructions::_fstore_1,
        &Instructions::_fstore_2,
        &Instructions::_fstore_3,
        &Instructions::_dstore_0,
        &Instructions::_dstore_1,
        &Instructions::_dstore_2,
        &Instructions::_dstore_3,
        &Instructions::_astore_0,
        &Instructions::_astore_1,
        &Instructions::_astore_2,
        &Instructions::_astore_3,
        &Instructions::_iastore,
        &Instructions::_lastore,
        &Instructions::_fastore,
        &Instructions::_dastore,
        &Instructions::_aastore,
        &Instructions::_bastore,
        &Instructions::_castore,
        &Instructions::_sastore,
        &Instructions::_pop,
        &Instructions::_pop2,
        &Instructions::_dup,
        &Instructions::_dup_x1,
        &Instructions::_dup_x2,
        &Instructions::_dup2,
        &Instructions::_dup2_x1,
        &Instructions::_dup2_x2,
        &Instructions::_swap,
        &Instructions::_iadd,
        &Instructions::_ladd,
        &Instructions::_fadd,
        &Instructions::_dadd,
        &Instructions::_isub,
        &Instructions::_lsub,
        &Instructions::_fsub,
        &Instructions::_dsub,
        &Instructions::_imul,
        &Instructions::_lmul,
        &Instructions::_fmul,
        &Instructions::_dmul,
        &Instructions::_idiv,
        &Instructions::_ldiv,
        &Instructions::_fdiv,
        &Instructions::_ddiv,
        &Instructions::_irem,
        &Instructions::_lrem,
        &Instructions::_frem,
        &Instructions::_drem,
        &Instructions::_ineg,
        &Instructions::_lneg,
        &Instructions::_fneg,
        &Instructions::_dneg,
        &Instructions::_ishl,
        &Instructions::_lshl,
        &Instructions::_ishr,
        &Instructions::_lshr,
        &Instructions::_iushr,
        &Instructions::_lushr,
        &Instructions::_iand,
        &Instructions::_land,
        &Instructions::_ior,
        &Instructions::_lor,
        &Instructions::_ixor,
        &Instructions::_lxor,
        &Instructions::_iinc,
        &Instructions::_i2l,
        &Instructions::_i2f,
        &Instructions::_i2d,
        &Instructions::_l2i,
        &Instructions::_l2f,
        &Instructions::_l2d,
        &Instructions::_f2i,
        &Instructions::_f2l,
        &Instructions::_f2d,
        &Instructions::_d2i,
        &Instructions::_d2l,
        &Instructions::_d2f,
        &Instructions::_i2b,
        &Instructions::_i2c,
        &Instructions::_i2s,
        &Instructions::_lcmp,
        &Instructions::_fcmpl,
        &Instructions::_fcmpg,
        &Instructions::_dcmpl,
        &Instructions::_dcmpg,
        &Instructions::_ifeq,
        &Instructions::_ifne,
        &Instructions::_iflt,
        &Instructions::_ifge,
        &Instructions::_ifgt,
        &Instructions::_ifle,
        &Instructions::_if_icmpeq,
        &Instructions::_if_icmpne,
        &Instructions::_if_icmplt,
        &Instructions::_if_icmpge,
        &Instructions::_if_icmpgt,
        &Instructions::_if_icmple,
        &Instructions::_if_acmpeq,
        &Instructions::_if_acmpne,
        &Instructions::_goto,
        &Instructions::_jsr,
        &Instructions::_ret,
        &Instructions::_tableswitch,
        &Instructions::_lookupswitch,
        &Instructions::_ireturn,
        &Instructions::_lreturn,
        &Instructions::_freturn,
        &Instructions::_dreturn,
        &Instructions::_areturn,
        &Instructions::_return,
        &Instructions::_getstatic,
        &Instructions::_putstatic,
        &Instructions::_getField,
        &Instructions::_putfield,
        &Instructions::_invokevirtual,
        &Instructions::_invokeSpecial,
        &Instructions::_invokestatic,
        nullptr, //Instructions::_invokeinterface,
        nullptr, //Instructions::_invokdynamic,
        &Instructions::_new,
        &Instructions::_newarray,
        &Instructions::_anewarray,
        &Instructions::_arraylength,
        &Instructions::_athrow,
        &Instructions::_checkcast,
        &Instructions::_instanceof,
        &Instructions::_monitorenter,
        &Instructions::_monitorexit,
        &Instructions::_wide,
        &Instructions::_multianewarray,
        &Instructions::_ifnull,
        &Instructions::_ifnonnull,
        &Instructions::_goto_w,
        &Instructions::_jsr_w
    };
}

void Instructions::execInstr(u1 opcode){
    instrFunction f = instrs[opcode];
    if (f != nullptr && opcode < instrs.size()) {
        (this->*f)();
    } else {
        addToPC(1);
    }
}

void Instructions::addToPC(int value) {
    frames.top().PC += value;
}

void Instructions::_nop(){
    addToPC(1);
}

void Instructions::_aconst_null(){
    Slot slot(SlotType::REFERENCE, 0);
    slot.ref.str = nullptr;
    slot.ref.object = nullptr;
    frames.top().operands.push(slot);
    addToPC(1);
}

void Instructions::_iconst_m1(){
    frames.top().operands.push(Slot(SlotType::INT, -1));
    addToPC(1);
}

void Instructions::_iconst_0(){
    frames.top().operands.push(Slot(SlotType::INT, 0));
    addToPC(1);
}

void Instructions::_iconst_1(){
    frames.top().operands.push(Slot(SlotType::INT, 1));
    addToPC(1);
}

void Instructions::_iconst_2(){
    frames.top().operands.push(Slot(SlotType::INT, 2));
    addToPC(1);
}

void Instructions::_iconst_3(){
    frames.top().operands.push(Slot(SlotType::INT, 3));
    addToPC(1);
}

void Instructions::_iconst_4(){
    frames.top().operands.push(Slot(SlotType::INT, 4));
    addToPC(1);
}

void Instructions::_iconst_5(){
    frames.top().operands.push(Slot(SlotType::INT, 5));
    addToPC(1);
}

void Instructions::_lconst_0(){
    frames.top().operands.pushLong(0);
    
    //long teste = frames.top().operands.popLong();
    //std::cout << teste << std::endl;
    addToPC(1);
}

void Instructions::_lconst_1(){
    frames.top().operands.pushLong(1);
    //long teste = frames.top().operands.popLong();
    //std::cout << "_lconst_1: " << teste << std::endl;
    addToPC(1);
}

void Instructions::_fconst_0(){
    float var = 0.0;
    u4 byte = reinterpret_cast<u4&>(var);
    frames.top().operands.push(Slot(SlotType::FLOAT, byte));
    //float teste = frames.top().operands.popFloat();
    //std::cout << teste << std::endl;
    addToPC(1);
}

void Instructions::_fconst_1(){
    float var = 1.0;
    u4 byte = reinterpret_cast<u4&>(var);
    frames.top().operands.push(Slot(SlotType::FLOAT, byte));
    addToPC(1);
}

void Instructions::_fconst_2(){
    float var = 2.0;
    u4 byte = reinterpret_cast<u4&>(var);
    frames.top().operands.push(Slot(SlotType::FLOAT, byte)); 
    addToPC(1);
}

void Instructions::_dconst_0(){
    double var = 0;
    frames.top().operands.pushDouble(var);
    //double teste = frames.top().operands.popDouble();
    //std::cout << teste << std::endl;
    addToPC(1);
}

void Instructions::_dconst_1(){
    double var = 1;
    frames.top().operands.pushDouble(var);
    //double teste = frames.top().operands.popDouble();
    //std::cout << "_dconst_1: " << teste << std::endl;
    addToPC(1);
}

void Instructions::_bipush(){
    Frame f = frames.top();
    int byte = getInt(f.bytecode[f.PC+1]);
    u4 v = reinterpret_cast<u4&>(byte);
    frames.top().operands.push(Slot(SlotType::INT,v));
    addToPC(2);
}

void Instructions::_sipush(){
    addToPC(1);
}

void Instructions::_ldc(){
    u1 idx = frames.top().bytecode[frames.top().PC+1];
    Cpinfo entry = frames.top().classFile->constantPool[idx-1];
    switch(entry.tag) {
        case CONSTANT_Integer:
            frames.top().operands.push(Slot(SlotType::INT, entry.Integer.bytes));
        break;
        case CONSTANT_Float:
            frames.top().operands.push(Slot(SlotType::FLOAT, entry.Float.bytes));
            //std::cout << std::to_string(frames.top().operands.popFloat()) << std::endl;
        break;
        case CONSTANT_String:
            Cpinfo entry2 = frames.top().classFile->constantPool[entry.String.stringIndex-1];
            Slot slot(SlotType::STRING_REF, entry.String.stringIndex);
            slot.ref.str = (char*)entry2.Utf8.bytes;
            frames.top().operands.push(slot);
            //std::cout << frames.top().operands.popString() << std::endl;
        break;
    }
    addToPC(2);
}

void Instructions::_ldc_w(){
    addToPC(3);
}

void Instructions::_ldc2_w() {
    u2 idx = getIndex(frames.top().bytecode[frames.top().PC+1], frames.top().bytecode[frames.top().PC+2]);
    Cpinfo value = frames.top().classFile->constantPool[idx-1];
    switch(value.tag) {
        case CONSTANT_Double:
            frames.top().operands.push(Slot(SlotType::DOUBLE, value.Double.lowBytes));
            frames.top().operands.push(Slot(SlotType::DOUBLE, value.Double.highBytes));
        break;
        case CONSTANT_Long:
            frames.top().operands.push(Slot(SlotType::LONG, value.Long.lowBytes));
            frames.top().operands.push(Slot(SlotType::LONG, value.Long.highBytes));
        break;
    }
    addToPC(3);
}

void Instructions::_iload(){
    Frame f = frames.top();
    u1 idx = f.bytecode[f.PC+1];
    frames.top().operands.push(f.variables.at(idx));
    addToPC(2);
}

void Instructions::_lload(){
    Frame f = frames.top();
    int idx = getInt(f.bytecode[f.PC+1]);
    long l = f.variables.asLong(idx);
    frames.top().operands.pushLong(l);
    addToPC(2);
}

void Instructions::_fload(){
    Frame f = frames.top();
    int idx = getInt(f.bytecode[f.PC+1]);
    float value = f.variables.asFloat(idx);
    u4 uf = reinterpret_cast<u4&>(value);
    frames.top().operands.push(Slot(SlotType::FLOAT, uf));
    addToPC(2);
}

void Instructions::_dload(){
    Frame f = frames.top();
    int idx = getInt(f.bytecode[f.PC+1]);
    double value = f.variables.asDouble(idx);
    frames.top().operands.pushDouble(value);
    addToPC(2);
}

void Instructions::_aload(){
    addToPC(1);
}

void Instructions::_iload_0(){
    Frame f = frames.top();
    frames.top().operands.push(f.variables.at(0));
    addToPC(1);
}

void Instructions::_iload_1(){
    Frame f = frames.top();
    frames.top().operands.push(f.variables.at(1));
    addToPC(1);
}

void Instructions::_iload_2(){
    Frame f = frames.top();
    frames.top().operands.push(f.variables.at(2));
    addToPC(1);
}

void Instructions::_iload_3(){
    Frame f = frames.top();
    frames.top().operands.push(f.variables.at(3));
    addToPC(1);
}

void Instructions::_lload_0(){
    Frame f = frames.top();
    long value = f.variables.asLong(0);
    frames.top().operands.pushLong(value);
    addToPC(1);
}

void Instructions::_lload_1(){
    Frame f = frames.top();
    long value = f.variables.asLong(1);
    frames.top().operands.pushLong(value);
    addToPC(1);
}

void Instructions::_lload_2(){
    Frame f = frames.top();
    long value = f.variables.asLong(2);
    frames.top().operands.pushLong(value);
    addToPC(1);
}

void Instructions::_lload_3(){
    Frame f = frames.top();
    long value = f.variables.asLong(3);
    frames.top().operands.pushLong(value);
    addToPC(1);
}

void Instructions::_fload_0(){
    Frame f = frames.top();
    float value = f.variables.asFloat(0);
    u4 uf = reinterpret_cast<u4&>(value);
    frames.top().operands.push(Slot(SlotType::FLOAT, uf));
    addToPC(1);
}

void Instructions::_fload_1(){
    Frame f = frames.top();
    float value = f.variables.asFloat(1);
    u4 uf = reinterpret_cast<u4&>(value);
    frames.top().operands.push(Slot(SlotType::FLOAT, uf));
    addToPC(1);
}

void Instructions::_fload_2(){
    Frame f = frames.top();
    float value = f.variables.asFloat(2);
    u4 uf = reinterpret_cast<u4&>(value);
    frames.top().operands.push(Slot(SlotType::FLOAT, uf));
    addToPC(1);
}

void Instructions::_fload_3(){
    Frame f = frames.top();
    float value = f.variables.asFloat(3);
    u4 uf = reinterpret_cast<u4&>(value);
    frames.top().operands.push(Slot(SlotType::FLOAT, uf));
    addToPC(1);
}

void Instructions::_dload_0(){
    Frame f = frames.top();
    double value = f.variables.asDouble(0);
    frames.top().operands.pushDouble(value);    
    addToPC(1);
}

void Instructions::_dload_1(){
    Frame f = frames.top();
    double value = f.variables.asDouble(1);
    frames.top().operands.pushDouble(value);    
    addToPC(1);
}

void Instructions::_dload_2(){
    Frame f = frames.top();
    double value = f.variables.asDouble(2);
    frames.top().operands.pushDouble(value);    
    addToPC(1);
}

void Instructions::_dload_3(){
    Frame f = frames.top();
    double value = f.variables.asDouble(3);
    frames.top().operands.pushDouble(value);    
    addToPC(1);
}

void Instructions::_aload_0(){
    addToPC(1);
}

void Instructions::_aload_1(){
    addToPC(1);
}

void Instructions::_aload_2(){
    addToPC(1);
}

void Instructions::_aload_3(){
    addToPC(1);
}

void Instructions::_iaload(){
    addToPC(1);
}

void Instructions::_laload(){
    addToPC(1);
}

void Instructions::_faload(){
    addToPC(1);
}

void Instructions::_daload(){
    addToPC(1);
}

void Instructions::_aaload(){
    addToPC(1);
}

void Instructions::_baload(){
    addToPC(1);
}

void Instructions::_caload(){
    addToPC(1);
}

void Instructions::_saload(){
    addToPC(1);
}

void Instructions::_istore(){
    u1 idx = frames.top().bytecode[frames.top().PC+1];
    frames.top().variables[idx] = frames.top().operands.top();
    frames.top().operands.pop();
    addToPC(2); 
}

void Instructions::_lstore(){
    long value = frames.top().operands.popLong();
    u1 idx = frames.top().bytecode[frames.top().PC+1];
    frames.top().variables.putLong(value, idx);
    addToPC(2);
}

void Instructions::_fstore(){
    float value = frames.top().operands.popFloat();
    u1 idx = frames.top().bytecode[frames.top().PC+1];
    u4 uv = reinterpret_cast<u4&>(value);
    frames.top().variables[idx] = Slot(SlotType::FLOAT, uv);
    addToPC(1);
}

void Instructions::_dstore(){
    double value = frames.top().operands.popDouble();
    u1 idx = frames.top().bytecode[frames.top().PC+1];
    frames.top().variables.putDouble(value, idx);
    addToPC(1);
}

void Instructions::_astore(){
    addToPC(1);
}

void Instructions::_istore_0(){
    int value = frames.top().operands.popInt();
    u4 uv = reinterpret_cast<u4&>(value);
    frames.top().variables[0] = Slot(SlotType::INT, uv);
    addToPC(1);
}

void Instructions::_istore_1(){
    int value = frames.top().operands.popInt();
    u4 uv = reinterpret_cast<u4&>(value);
    frames.top().variables[1] = Slot(SlotType::INT, uv);
    addToPC(1);
}

void Instructions::_istore_2(){
    int value = frames.top().operands.popInt();
    u4 uv = reinterpret_cast<u4&>(value);
    frames.top().variables[2] = Slot(SlotType::INT, uv);
    addToPC(1);
}

void Instructions::_istore_3(){
    int value = frames.top().operands.popInt();
    u4 uv = reinterpret_cast<u4&>(value);
    frames.top().variables[3] = Slot(SlotType::INT, uv);
    addToPC(1);
}

void Instructions::_lstore_0(){
    long value = frames.top().operands.popLong();
    frames.top().variables.putLong(value, 0);
    addToPC(1);
}

void Instructions::_lstore_1(){
    long value = frames.top().operands.popLong();
    frames.top().variables.putLong(value, 1);
    addToPC(1);
}

void Instructions::_lstore_2(){
    long value = frames.top().operands.popLong();
    frames.top().variables.putLong(value, 2); 
    addToPC(1);
}

void Instructions::_lstore_3(){
    long value = frames.top().operands.popLong();
    frames.top().variables.putLong(value, 3);  
    addToPC(1);
}

void Instructions::_fstore_0(){
    float value = frames.top().operands.popFloat();
    u4 uv = reinterpret_cast<u4&>(value);
    frames.top().variables[0] = Slot(SlotType::FLOAT, uv);    
    addToPC(1);
}

void Instructions::_fstore_1(){
    float value = frames.top().operands.popFloat();
    u4 uv = reinterpret_cast<u4&>(value);
    frames.top().variables[1] = Slot(SlotType::FLOAT, uv);  
    addToPC(1);
}

void Instructions::_fstore_2(){
    float value = frames.top().operands.popFloat();
    u4 uv = reinterpret_cast<u4&>(value);
    frames.top().variables[2] = Slot(SlotType::FLOAT, uv);  
    addToPC(1);
}

void Instructions::_fstore_3(){
    float value = frames.top().operands.popFloat();
    u4 uv = reinterpret_cast<u4&>(value);
    frames.top().variables[3] = Slot(SlotType::FLOAT, uv);  
    addToPC(1);
}

void Instructions::_dstore_0(){
    double value = frames.top().operands.popDouble();
    frames.top().variables.putDouble(value, 0); 
    addToPC(1);
}

void Instructions::_dstore_1(){
    double value = frames.top().operands.popDouble();
    frames.top().variables.putDouble(value, 1);  
    addToPC(1);
}

void Instructions::_dstore_2(){
    double value = frames.top().operands.popDouble();
    frames.top().variables.putDouble(value, 2);   
    addToPC(1);
}

void Instructions::_dstore_3(){
    double value = frames.top().operands.popDouble();
    frames.top().variables.putDouble(value, 3); 
    addToPC(1);
}

void Instructions::_astore_0(){
    addToPC(1);
}

void Instructions::_astore_1(){
    addToPC(1);
}

void Instructions::_astore_2(){
    addToPC(1);
}

void Instructions::_astore_3(){
    addToPC(1);
}

void Instructions::_iastore(){
    addToPC(1);
}

void Instructions::_lastore(){
    addToPC(1);
}

void Instructions::_fastore(){
    addToPC(1);
}

void Instructions::_dastore(){
    addToPC(1);
}

void Instructions::_aastore(){
    addToPC(1);
}

void Instructions::_bastore(){
    addToPC(1);
}

void Instructions::_castore(){
    addToPC(1);
}

void Instructions::_sastore(){
    addToPC(1);
}

void Instructions::_pop(){
    Slot slot;
    frames.top().operands.pop();
    //assert(slot.type != SlotType::LONG);
    //assert(slot.type != SlotType::DOUBLE);
    addToPC(1);
}

void Instructions::_pop2(){
    frames.top().operands.pop();
    frames.top().operands.pop();
    addToPC(1);
}

void Instructions::_dup(){
    addToPC(1);
}

void Instructions::_dup_x1(){
    addToPC(1);
}

void Instructions::_dup_x2(){
    addToPC(1);
}

void Instructions::_dup2(){
    addToPC(1);
}

void Instructions::_dup2_x1(){
    addToPC(1);
}

void Instructions::_dup2_x2(){
    addToPC(1);
}

void Instructions::_swap(){
    addToPC(1);
}

void Instructions::_iadd(){
    addToPC(1);
}

void Instructions::_ladd(){
    long l1 = frames.top().operands.popLong();
    long l2 = frames.top().operands.popLong();
    frames.top().operands.pushLong(l1+l2);
    addToPC(1);
}

void Instructions::_fadd(){
    addToPC(1);
}

void Instructions::_dadd(){
    addToPC(1);
}

void Instructions::_isub(){
    addToPC(1);
}

void Instructions::_lsub(){
    addToPC(1);
}

void Instructions::_fsub(){
    addToPC(1);
}

void Instructions::_dsub(){
    addToPC(1);
}

void Instructions::_imul(){
    addToPC(1);
}

void Instructions::_lmul(){
    addToPC(1);
}

void Instructions::_fmul(){
    addToPC(1);
}

void Instructions::_dmul(){
    addToPC(1);
}

void Instructions::_idiv(){
    addToPC(1);
}

void Instructions::_ldiv(){
    addToPC(1);
}

void Instructions::_fdiv(){
    addToPC(1);
}

void Instructions::_ddiv(){
    addToPC(1);
}

void Instructions::_irem(){
    addToPC(1);
}

void Instructions::_lrem(){
    addToPC(1);
}

void Instructions::_frem(){
    addToPC(1);
}

void Instructions::_drem(){
    addToPC(1);
}

void Instructions::_ineg(){
    addToPC(1);
}

void Instructions::_lneg(){
    addToPC(1);
}

void Instructions::_fneg(){
    addToPC(1);
}

void Instructions::_dneg(){
    addToPC(1);
}

void Instructions::_ishl(){
    addToPC(1);
}

void Instructions::_lshl(){
    addToPC(1);
}

void Instructions::_ishr(){
    addToPC(1);
}

void Instructions::_lshr(){
    addToPC(1);
}

void Instructions::_iushr(){
    addToPC(1);
}

void Instructions::_lushr(){
    addToPC(1);
}

void Instructions::_iand(){
    addToPC(1);
}

void Instructions::_land(){
    addToPC(1);
}

void Instructions::_ior(){
    addToPC(1);
}

void Instructions::_lor(){
    addToPC(1);
}

void Instructions::_ixor(){
    addToPC(1);
}

void Instructions::_lxor(){
    addToPC(1);
}

void Instructions::_iinc(){
    Frame f = frames.top();
    int idx = getInt(f.bytecode[f.PC+1]);
    int8_t const_ = f.bytecode[f.PC+2];
    int value = f.variables.asInt(idx);
    frames.top().variables[idx].value = value + (int)const_;
    addToPC(3);
}

void Instructions::_i2l(){
    addToPC(1);
}

void Instructions::_i2f(){
    addToPC(1);
}

void Instructions::_i2d(){
    addToPC(1);
}

void Instructions::_l2i(){
    addToPC(1);
}

void Instructions::_l2f(){
    addToPC(1);
}

void Instructions::_l2d(){
    addToPC(1);
}

void Instructions::_f2i(){
    addToPC(1);
}

void Instructions::_f2l(){
    addToPC(1);
}

void Instructions::_f2d(){
    addToPC(1);
}

void Instructions::_d2i(){
    addToPC(1);
}

void Instructions::_d2l(){
    addToPC(1);
}

void Instructions::_d2f(){
    addToPC(1);
}

void Instructions::_i2b(){
    addToPC(1);
}

void Instructions::_i2c(){
    addToPC(1);
}

void Instructions::_i2s(){
    addToPC(1);
}

void Instructions::_lcmp(){
    addToPC(1);
}

void Instructions::_fcmpl(){
    addToPC(1);
}

void Instructions::_fcmpg(){
    addToPC(1);
}

void Instructions::_dcmpl(){
    addToPC(1);
}

void Instructions::_dcmpg(){
    addToPC(1);
}

void Instructions::_ifeq(){
    addToPC(1);
}

void Instructions::_ifne(){
    addToPC(1);
}

void Instructions::_iflt(){
    addToPC(1);
}

void Instructions::_ifge(){
    addToPC(1);
}

void Instructions::_ifgt(){
    addToPC(1);
}

void Instructions::_ifle(){
    addToPC(1);
}

void Instructions::_if_icmpeq(){
    Frame f = frames.top();
    u1 branchbyte1 = f.bytecode[f.PC+1];
    u1 branchbyte2 = f.bytecode[f.PC+2];
    u2 br = getIndex(branchbyte1, branchbyte2);
    int v2 = f.operands.popInt();
    int v1 = f.operands.popInt();
    if(v1 == v2) addToPC(br);
    else         addToPC(3);
}

void Instructions::_if_icmpne(){
    Frame f = frames.top();
    u1 branchbyte1 = f.bytecode[f.PC+1];
    u1 branchbyte2 = f.bytecode[f.PC+2];
    u2 br = getIndex(branchbyte1, branchbyte2);
    int v2 = f.operands.popInt();
    int v1 = f.operands.popInt();
    if(v1 != v2) addToPC(br);
    else         addToPC(3);
}

void Instructions::_if_icmplt(){
    Frame f = frames.top();
    u1 branchbyte1 = f.bytecode[f.PC+1];
    u1 branchbyte2 = f.bytecode[f.PC+2];
    u2 br = getIndex(branchbyte1, branchbyte2);
    int v2 = f.operands.popInt();
    int v1 = f.operands.popInt();
    if(v1 < v2) addToPC(br);
    else         addToPC(3);
}

void Instructions::_if_icmpge(){
    Frame f = frames.top();
    u1 branchbyte1 = f.bytecode[f.PC+1];
    u1 branchbyte2 = f.bytecode[f.PC+2];
    u2 br = getIndex(branchbyte1, branchbyte2);
    int v2 = f.operands.popInt();
    int v1 = f.operands.popInt();
    if(v1 >= v2) addToPC(br);
    else         addToPC(3);
}

void Instructions::_if_icmpgt(){
    Frame f = frames.top();
    u1 branchbyte1 = f.bytecode[f.PC+1];
    u1 branchbyte2 = f.bytecode[f.PC+2];
    u2 br = getIndex(branchbyte1, branchbyte2);
    int v2 = f.operands.popInt();
    int v1 = f.operands.popInt();
    if(v1 > v2) addToPC(br);
    else        addToPC(3);
}

void Instructions::_if_icmple(){
    Frame f = frames.top();
    u1 branchbyte1 = f.bytecode[f.PC+1];
    u1 branchbyte2 = f.bytecode[f.PC+2];
    u2 br = getIndex(branchbyte1, branchbyte2);
    int v2 = f.operands.popInt();
    int v1 = f.operands.popInt();
    if(v1 <= v2) addToPC(br);
    else         addToPC(3);
}

void Instructions::_if_acmpeq(){
    addToPC(1);
}

void Instructions::_if_acmpne(){
    addToPC(1);
}

void Instructions::_goto(){
    Frame f = frames.top();
    u1 branchbyte1 = f.bytecode[f.PC+1];
    u1 branchbyte2 = f.bytecode[f.PC+2];
    u2 ubr = getIndex(branchbyte1, branchbyte2);
    int br = static_cast<int16_t>(ubr) + static_cast<int16_t>(f.PC);
    frames.top().PC =  reinterpret_cast<u4&>(br);
}

void Instructions::_jsr(){
    addToPC(1);
}

void Instructions::_ret(){
    addToPC(1);
}

void Instructions::_tableswitch(){
    addToPC(1);
}

void Instructions::_lookupswitch(){
    addToPC(1);
}

void Instructions::_ireturn(){
    frames.pop();
}

void Instructions::_lreturn(){
    frames.pop();
}

void Instructions::_freturn(){
    frames.pop();
}

void Instructions::_dreturn(){
    frames.pop();
}

void Instructions::_areturn(){
    frames.pop();
}

void Instructions::_return(){
    frames.pop();
}

void Instructions::_getstatic(){
    Frame f = frames.top();
    u1 idx1 = f.bytecode[f.PC+1];
    u1 idx2 = f.bytecode[f.PC+2];
    u2 idx = getIndex(idx1, idx2);
    u2 idxclass = f.classFile->constantPool[idx].FieldMethInter.classIndex;
    std::string classname = f.classFile->constantPool.getUtf8Class(idxclass);
    char s[classname.size()];
    Slot slot(SlotType::STRING_REF, 0);
    strcpy(s, classname.c_str());
    slot.ref.str = s;
    frames.top().operands.push(slot);
    addToPC(3);
}

void Instructions::_putstatic(){
    addToPC(1);
}

void Instructions::_getField(){
    addToPC(1);
}

void Instructions::_putfield(){
    addToPC(1);
}

void Instructions::_invokevirtual(){
    Frame f = frames.top();
    u1 idx1 = f.bytecode[f.PC+1];
    u1 idx2 = f.bytecode[f.PC+2];
    u2 idx = getIndex(idx1, idx2);
    
    ConstantPool cpt = f.classFile->constantPool;
    Cpinfo cpmthd = cpt[idx-1];
    std::string name = cpt.getNNameAndType(cpmthd.FieldMethInter.nameTypeIndex-1);
    std::string descriptor = cpt.getDescriptor(cpmthd.FieldMethInter.nameTypeIndex-1);
    
    if(name == "println") print(true);
    else if(name == "print") print(false);
    else initGenericMethod(frames, name, descriptor);
    addToPC(3);
}

void Instructions::_invokeSpecial(){
    addToPC(1);
}

void Instructions::_invokestatic(){
    Frame f = frames.top();
    u1 idx1 = f.bytecode[f.PC+1];
    u1 idx2 = f.bytecode[f.PC+2];
    u2 idx = getIndex(idx1, idx2);
    ConstantPool cpt = f.classFile->constantPool;
    std::string name = cpt.getNNameAndType(idx);
    std::string descriptor = cpt.getDescriptor(idx);
    initGenericMethod(frames, name, descriptor);
    addToPC(3);
}

/*void Instructions::_invokeinterface(){
    addToPC(1);
}
*/

/*void Instructions::_invokdynamic(){
    addToPC(1);
}
*/

void Instructions::_new(){
    addToPC(1);
}

void Instructions::_newarray(){
    Frame f = frames.top();
    u4 atype = f.bytecode[f.PC+1] | 0x0000 ;
    u4 count = f.operands.popInt();

    Array array = Array(Array::type(atype), count, 1);
    array.dimensions.push_back(1);
    switch (array.atype){
    case Array::type::T_BOOLEAN :
        // std::array<bool,reinterpret_cast<int&>(array.size)>
        array.values = new bool[array.size];
        break;
    case Array::type::T_BYTE :
        array.values = new u1[array.size];
        break;
    case Array::type::T_CHAR :
        array.values = new char[array.size];
        break;
    case Array::type::T_DOUBLE :
        array.values = new double[array.size];
        break;
    case Array::type::T_FLOAT :
        array.values = new float[array.size];
        break;
    case Array::type::T_INT :
        array.values = new int[array.size];
        break;
    case Array::type::T_LONG :
        array.values = new long[array.size];
        break;
    case Array::type::T_SHORT :
        array.values = new short[array.size];
        break;    
    default:
        std::cout << "Tipo do array inválido" << std::endl;
        break;
    }
    heap.push_back(&array);
    frames.top().operands.push(Slot(SlotType::REFERENCE, heap.size()-1));
    addToPC(2);
}

void Instructions::_anewarray(){
    Frame f = frames.top();
    u2 idx = getIndex(f.bytecode[f.PC+1], f.bytecode[f.PC+2]);
    Cpinfo cp = f.classFile->constantPool[idx-1];
    u4 count = f.operands.popInt();

    Array array = Array(count);
    array.dimensions.push_back(1);
    switch (cp.tag){
    case CONSTANT_Class:
        array.atype = Array::type::T_CLASS;
        break;
    // case array. tipo array?
    case CONSTANT_InterfaceMethodref :
        array.atype = Array::type::T_INTERFACE;
        break;    
    default:
        std::cout << "Tipo do array inválido" << std::endl;
        break;
    }
    array.values = new int* [array.size];
    heap.push_back(&array);
    frames.top().operands.push(Slot(SlotType::REFERENCE, heap.size()-1));
    addToPC(3);  
}

void Instructions::_arraylength(){
    addToPC(1);
}

void Instructions::_athrow(){
    addToPC(1);
}

void Instructions::_checkcast(){
    addToPC(1);
}

void Instructions::_instanceof(){
    addToPC(1);
}

void Instructions::_monitorenter(){
    addToPC(1);
}

void Instructions::_monitorexit(){
    addToPC(1);
}

void Instructions::_wide(){
    addToPC(1);
}

void Instructions::_multianewarray(){
    Frame f = frames.top();
    u2 idx = getIndex(f.bytecode[f.PC+1], f.bytecode[f.PC+2]);
    int dim = getInt(f.bytecode[f.PC+3] | 0x0000);
    Array::type mtxtype;

    Cpinfo cp = f.classFile->constantPool[idx-1];
    switch (cp.tag){
    case CONSTANT_Class:
        mtxtype = Array::type::T_CLASS;
        //std::cout << f.classFile->constantPool.getUtf8Class(idx-1) << std::endl;
        break;
    // case array. tipo array?
    case CONSTANT_InterfaceMethodref :
        mtxtype = Array::type::T_INTERFACE;
        //std::cout << f.classFile->constantPool.getNNameAndType(cp.FieldMethInter.nameTypeIndex-1) << std::endl;
        break;    
    default:
        std::cout << "Tipo do array inválido" << std::endl;
        break;
    }

    Array mtx = Array(mtxtype, dim);
    for(int d=0; d<dim; d++){
        mtx.dimensions.push_back(f.operands.popInt());
        mtx.size *= mtx.dimensions.back();
    }
    mtx.values = new int* [mtx.size];
    heap.push_back(&mtx);
    frames.top().operands.push(Slot(SlotType::REFERENCE, heap.size()-1));
    addToPC(4);      
    //std::cout << idx << std::endl;  
    //std::cout << dim << std::endl;

    /* modelo de uso
    auto vals = reinterpret_cast<int*>(mtx.values);
    int idxs[] = {1, 1};
    std::cout << vals[mtx.offset(idxs)] << std::endl;
    */
}

void Instructions::_ifnull(){
    addToPC(1);
}

void Instructions::_ifnonnull(){
    addToPC(1);
}

void Instructions::_goto_w(){
    addToPC(1);
}

void Instructions::_jsr_w(){
    addToPC(1);
}


int Array::offset(int* idxs){
    int offset=0;
    for(int d=1; d<=dim; d++){
        int p=1;
        for(int j=d+1; j<=dim; j++){
            p *= dimensions[j-1];
        }
        offset += p*idxs[d-1];
    }
    return offset;
}


void Instructions::initGenericMethod(std::stack<Frame>& frames, std::string name, std::string descriptor){
	Frame f = frames.top();
    MethodInfo* mthinfo;
    for(auto mth : frames.top().classFile->methods){
        if(!(mth->name + mth->descriptor).compare(name+descriptor)){
            mthinfo = mth;
            break;
        }
    }
	Frame newframe(f.classFile, mthinfo);
    int qtd = getNumberArgs(descriptor);
    for(u1 q=0; q<qtd; q++){
        newframe.variables[q] = f.operands.top();
        frames.top().operands.pop();
    }
    frames.push(newframe);	
}

int Instructions::getNumberArgs(std::string descriptor){
	int qtd = 0;
	std::size_t p = std::string::npos;

	std::size_t refpos = descriptor.find_first_of("L");
	if(refpos != p){
		qtd++;
		std::size_t ppos = descriptor.find_first_of(";");
		descriptor.erase(refpos, ppos-refpos);
	}
	std::size_t c = descriptor.find_first_of("BCDFIJSZ");
	for(;c != p;++qtd) c = descriptor.find_first_of("BCDFIJSZ", c+1);

	if(descriptor.find_first_of("[") != p ) qtd++;
	return qtd;
}

void Instructions::print(bool newline){
    SlotType type = frames.top().operands.top().type;
    switch(type){
        case SlotType::BOOL:
            std::cout << frames.top().operands.popBool();
            break;
        case SlotType::BYTE:
            std::cout << frames.top().operands.top().value;
            frames.top().operands.pop();
            break;
        case SlotType::CHAR:
        {
            char c = reinterpret_cast<char&>(frames.top().operands.top().value);
            frames.top().operands.pop();
            std::cout << (char)c;
            break;
        }
        case SlotType::INT:
            std::cout << frames.top().operands.popInt();
            break;
        case SlotType::FLOAT:
            std::cout << frames.top().operands.popFloat();
            break;
        case SlotType::LONG:
            std::cout << (long)frames.top().operands.popLong();
            break;
        case SlotType::DOUBLE:
            std::cout << frames.top().operands.popDouble();
            break;
        case SlotType::STRING_REF:
            std::cout << frames.top().operands.popString();
            break;
        default:
            std::cout << "Tipo invalido para impressão";
            break;
    }
    if(newline) std::cout <<  std::endl;
}
