#include "Instructions.h"


Instructions::Instructions(u4 PC, /*std::stack<Frame> frames,*/ std::vector<ClassFile> classes):
    PC(PC), /*frames(frames),*/ classes(classes){
    instrs = {
        &_nop,
        &_aconst_null,
        &_iconst_m1,
        &_iconst_0,
        &_iconst_1,
        &_iconst_2,
        &_iconst_3,
        &_iconst_4,
        &_iconst_5,
        &_lconst_0,
        &_lconst_1,
        &_fconst_0,
        &_fconst_1,
        &_fconst_2,
        &_dconst_0,
        &_dconst_1,
        &_bipush,
        &_sipush,
        &_ldc,
        &_ldc_w,
        &_ldc2_w,
        &_iload,
        &_lload,
        &_fload,
        &_dload,
        &_aload,
        &_iload_0,
        &_iload_1,
        &_iload_2,
        &_iload_3,
        &_lload_0,
        &_lload_1,
        &_lload_2,
        &_lload_3,
        &_fload_0,
        &_fload_1,
        &_fload_2,
        &_fload_3,
        &_dload_0,
        &_dload_1,
        &_dload_2,
        &_dload_3,
        &_aload_0,
        &_aload_1,
        &_aload_2,
        &_aload_3,
        &_iaload,
        &_laload,
        &_faload,
        &_daload,
        &_aaload,
        &_baload,
        &_caload,
        &_saload,
        &_istore,
        &_lstore,
        &_fstore,
        &_dstore,
        &_astore,
        &_istore_0,
        &_istore_1,
        &_istore_2,
        &_istore_3,
        &_lstore_0,
        &_lstore_1,
        &_lstore_2,
        &_lstore_3,
        &_fstore_0,
        &_fstore_1,
        &_fstore_2,
        &_fstore_3,
        &_dstore_0,
        &_dstore_1,
        &_dstore_2,
        &_dstore_3,
        &_astore_0,
        &_astore_1,
        &_astore_2,
        &_astore_3,
        &_iastore,
        &_lastore,
        &_fastore,
        &_dastore,
        &_aastore,
        &_bastore,
        &_castore,
        &_sastore,
        &_pop,
        &_pop2,
        &_dup,
        &_dup_x1,
        &_dup_x2,
        &_dup2,
        &_dup2_x1,
        &_dup2_x2,
        &_swap,
        &_iadd,
        &_ladd,
        &_fadd,
        &_dadd,
        &_isub,
        &_lsub,
        &_fsub,
        &_dsub,
        &_imul,
        &_lmul,
        &_fmul,
        &_dmul,
        &_idiv,
        &_ldiv,
        &_fdiv,
        &_ddiv,
        &_irem,
        &_lrem,
        &_frem,
        &_drem,
        &_ineg,
        &_lneg,
        &_fneg,
        &_dneg,
        &_ishl,
        &_lshl,
        &_ishr,
        &_lshr,
        &_iushr,
        &_lushr,
        &_iand,
        &_land,
        &_ior,
        &_lor,
        &_ixor,
        &_lxor,
        &_iinc,
        &_i2l,
        &_i2f,
        &_i2d,
        &_l2i,
        &_l2f,
        &_l2d,
        &_f2i,
        &_f2l,
        &_f2d,
        &_d2i,
        &_d2l,
        &_d2f,
        &_i2b,
        &_i2c,
        &_i2s,
        &_lcmp,
        &_fcmpl,
        &_fcmpg,
        &_dcmpl,
        &_dcmpg,
        &_ifeq,
        &_ifne,
        &_iflt,
        &_ifge,
        &_ifgt,
        &_ifle,
        &_if_icmpeq,
        &_if_icmpne,
        &_if_icmplt,
        &_if_icmpge,
        &_if_icmpgt,
        &_if_icmple,
        &_if_acmpeq,
        &_if_acmpne,
        &_goto,
        &_jsr,
        &_ret,
        &_tableswitch,
        &_lookupswitch,
        &_ireturn,
        &_lreturn,
        &_freturn,
        &_dreturn,
        &_areturn,
        &_return,
        &_getstatic,
        &_putstatic,
        &_getField,
        &_putfield,
        &_invokevirtual,
        &_invokeSpecial,
        &_invokestatic,
        nullptr, //&_invokeinterface,
        nullptr, //&_invokdynamic,
        &_new,
        &_newarray,
        &_anewarray,
        &_arraylength,
        &_athrow,
        &_checkcast,
        &_instanceof,
        &_monitorenter,
        &_monitorexit,
        &_wide,
        &_multianewarray,
        &_ifnull,
        &_ifnonnull,
        &_goto_w,
        &_jsr_w
    };
}

void Instructions::_nop(){
    //...
}

void Instructions::_aconst_null(){
    //...
}

void Instructions::_iconst_m1(){
    //...
}

void Instructions::_iconst_0(){
    //...
}

void Instructions::_iconst_1(){
    //...
}

void Instructions::_iconst_2(){
    //...
}

void Instructions::_iconst_3(){
    //...
}

void Instructions::_iconst_4(){
    //...
}

void Instructions::_iconst_5(){
    //...
}

void Instructions::_lconst_0(){
    //...
}

void Instructions::_lconst_1(){
    //...
}

void Instructions::_fconst_0(){
    //...
}

void Instructions::_fconst_1(){
    //...
}

void Instructions::_fconst_2(){
    //...
}

void Instructions::_dconst_0(){
    //...
}

void Instructions::_dconst_1(){
    //...
}

void Instructions::_bipush(){
    //...
}

void Instructions::_sipush(){
    //...
}

void Instructions::_ldc(){
    //...
}

void Instructions::_ldc_w(){
    //...
}

void Instructions::_ldc2_w(){
    //...
}

void Instructions::_iload(){
    //...
}

void Instructions::_lload(){
    //...
}

void Instructions::_fload(){
    //...
}

void Instructions::_dload(){
    //...
}

void Instructions::_aload(){
    //...
}

void Instructions::_iload_0(){
    //...
}

void Instructions::_iload_1(){
    //...
}

void Instructions::_iload_2(){
    //...
}

void Instructions::_iload_3(){
    //...
}

void Instructions::_lload_0(){
    //...
}

void Instructions::_lload_1(){
    //...
}

void Instructions::_lload_2(){
    //...
}

void Instructions::_lload_3(){
    //...
}

void Instructions::_fload_0(){
    //...
}

void Instructions::_fload_1(){
    //...
}

void Instructions::_fload_2(){
    //...
}

void Instructions::_fload_3(){
    //...
}

void Instructions::_dload_0(){
    //...
}

void Instructions::_dload_1(){
    //...
}

void Instructions::_dload_2(){
    //...
}

void Instructions::_dload_3(){
    //...
}

void Instructions::_aload_0(){
    //...
}

void Instructions::_aload_1(){
    //...
}

void Instructions::_aload_2(){
    //...
}

void Instructions::_aload_3(){
    //...
}

void Instructions::_iaload(){
    //...
}

void Instructions::_laload(){
    //...
}

void Instructions::_faload(){
    //...
}

void Instructions::_daload(){
    //...
}

void Instructions::_aaload(){
    //...
}

void Instructions::_baload(){
    //...
}

void Instructions::_caload(){
    //...
}

void Instructions::_saload(){
    //...
}

void Instructions::_istore(){
    //...
}

void Instructions::_lstore(){
    //...
}

void Instructions::_fstore(){
    //...
}

void Instructions::_dstore(){
    //...
}

void Instructions::_astore(){
    //...
}

void Instructions::_istore_0(){
    //...
}

void Instructions::_istore_1(){
    //...
}

void Instructions::_istore_2(){
    //...
}

void Instructions::_istore_3(){
    //...
}

void Instructions::_lstore_0(){
    //...
}

void Instructions::_lstore_1(){
    //...
}

void Instructions::_lstore_2(){
    //...
}

void Instructions::_lstore_3(){
    //...
}

void Instructions::_fstore_0(){
    //...
}

void Instructions::_fstore_1(){
    //...
}

void Instructions::_fstore_2(){
    //...
}

void Instructions::_fstore_3(){
    //...
}

void Instructions::_dstore_0(){
    //...
}

void Instructions::_dstore_1(){
    //...
}

void Instructions::_dstore_2(){
    //...
}

void Instructions::_dstore_3(){
    //...
}

void Instructions::_astore_0(){
    //...
}

void Instructions::_astore_1(){
    //...
}

void Instructions::_astore_2(){
    //...
}

void Instructions::_astore_3(){
    //...
}

void Instructions::_iastore(){
    //...
}

void Instructions::_lastore(){
    //...
}

void Instructions::_fastore(){
    //...
}

void Instructions::_dastore(){
    //...
}

void Instructions::_aastore(){
    //...
}

void Instructions::_bastore(){
    //...
}

void Instructions::_castore(){
    //...
}

void Instructions::_sastore(){
    //...
}

void Instructions::_pop(){
    //...
}

void Instructions::_pop2(){
    //...
}

void Instructions::_dup(){
    //...
}

void Instructions::_dup_x1(){
    //...
}

void Instructions::_dup_x2(){
    //...
}

void Instructions::_dup2(){
    //...
}

void Instructions::_dup2_x1(){
    //...
}

void Instructions::_dup2_x2(){
    //...
}

void Instructions::_swap(){
    //...
}

void Instructions::_iadd(){
    //...
}

void Instructions::_ladd(){
    //...
}

void Instructions::_fadd(){
    //...
}

void Instructions::_dadd(){
    //...
}

void Instructions::_isub(){
    //...
}

void Instructions::_lsub(){
    //...
}

void Instructions::_fsub(){
    //...
}

void Instructions::_dsub(){
    //...
}

void Instructions::_imul(){
    //...
}

void Instructions::_lmul(){
    //...
}

void Instructions::_fmul(){
    //...
}

void Instructions::_dmul(){
    //...
}

void Instructions::_idiv(){
    //...
}

void Instructions::_ldiv(){
    //...
}

void Instructions::_fdiv(){
    //...
}

void Instructions::_ddiv(){
    //...
}

void Instructions::_irem(){
    //...
}

void Instructions::_lrem(){
    //...
}

void Instructions::_frem(){
    //...
}

void Instructions::_drem(){
    //...
}

void Instructions::_ineg(){
    //...
}

void Instructions::_lneg(){
    //...
}

void Instructions::_fneg(){
    //...
}

void Instructions::_dneg(){
    //...
}

void Instructions::_ishl(){
    //...
}

void Instructions::_lshl(){
    //...
}

void Instructions::_ishr(){
    //...
}

void Instructions::_lshr(){
    //...
}

void Instructions::_iushr(){
    //...
}

void Instructions::_lushr(){
    //...
}

void Instructions::_iand(){
    //...
}

void Instructions::_land(){
    //...
}

void Instructions::_ior(){
    //...
}

void Instructions::_lor(){
    //...
}

void Instructions::_ixor(){
    //...
}

void Instructions::_lxor(){
    //...
}

void Instructions::_iinc(){
    //...
}

void Instructions::_i2l(){
    //...
}

void Instructions::_i2f(){
    //...
}

void Instructions::_i2d(){
    //...
}

void Instructions::_l2i(){
    //...
}

void Instructions::_l2f(){
    //...
}

void Instructions::_l2d(){
    //...
}

void Instructions::_f2i(){
    //...
}

void Instructions::_f2l(){
    //...
}

void Instructions::_f2d(){
    //...
}

void Instructions::_d2i(){
    //...
}

void Instructions::_d2l(){
    //...
}

void Instructions::_d2f(){
    //...
}

void Instructions::_i2b(){
    //...
}

void Instructions::_i2c(){
    //...
}

void Instructions::_i2s(){
    //...
}

void Instructions::_lcmp(){
    //...
}

void Instructions::_fcmpl(){
    //...
}

void Instructions::_fcmpg(){
    //...
}

void Instructions::_dcmpl(){
    //...
}

void Instructions::_dcmpg(){
    //...
}

void Instructions::_ifeq(){
    //...
}

void Instructions::_ifne(){
    //...
}

void Instructions::_iflt(){
    //...
}

void Instructions::_ifge(){
    //...
}

void Instructions::_ifgt(){
    //...
}

void Instructions::_ifle(){
    //...
}

void Instructions::_if_icmpeq(){
    //...
}

void Instructions::_if_icmpne(){
    //...
}

void Instructions::_if_icmplt(){
    //...
}

void Instructions::_if_icmpge(){
    //...
}

void Instructions::_if_icmpgt(){
    //...
}

void Instructions::_if_icmple(){
    //...
}

void Instructions::_if_acmpeq(){
    //...
}

void Instructions::_if_acmpne(){
    //...
}

void Instructions::_goto(){
    //...
}

void Instructions::_jsr(){
    //...
}

void Instructions::_ret(){
    //...
}

void Instructions::_tableswitch(){
    //...
}

void Instructions::_lookupswitch(){
    //...
}

void Instructions::_ireturn(){
    //...
}

void Instructions::_lreturn(){
    //...
}

void Instructions::_freturn(){
    //...
}

void Instructions::_dreturn(){
    //...
}

void Instructions::_areturn(){
    //...
}

void Instructions::_return(){
    //...
}

void Instructions::_getstatic(){
    //...
}

void Instructions::_putstatic(){
    //...
}

void Instructions::_getField(){
    //...
}

void Instructions::_putfield(){
    //...
}

void Instructions::_invokevirtual(){
    //...
}

void Instructions::_invokeSpecial(){
    //...
}

void Instructions::_invokestatic(){
    //...
}

/*void Instructions::_invokeinterface(){
    //...
}
*/

/*void Instructions::_invokdynamic(){
    //...
}
*/

void Instructions::_new(){
    //...
}

void Instructions::_newarray(){
    //...
}

void Instructions::_anewarray(){
    //...
}

void Instructions::_arraylength(){
    //...
}

void Instructions::_athrow(){
    //...
}

void Instructions::_checkcast(){
    //...
}

void Instructions::_instanceof(){
    //...
}

void Instructions::_monitorenter(){
    //...
}

void Instructions::_monitorexit(){
    //...
}

void Instructions::_wide(){
    //...
}

void Instructions::_multianewarray(){
    //...
}

void Instructions::_ifnull(){
    //...
}

void Instructions::_ifnonnull(){
    //...
}

void Instructions::_goto_w(){
    //...
}

void Instructions::_jsr_w(){
    //...
}



