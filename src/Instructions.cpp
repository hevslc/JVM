#include "Instructions.h"


Instructions::Instructions(u4 PC, /*std::stack<Frame> frames,*/ std::vector<ClassFile> classes):
    PC(PC), /*frames(frames),*/ classes(classes){
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



