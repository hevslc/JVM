#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "Definitions.h"
#include "ClassFile.h"
#include "Frame.h"
#include "Utils.h"
#include "CpInfo.h"

class Instructions;
typedef void (Instructions::*instrFunction)(); /*!< Ponteiro para um método de Instructions */

//! \class Instructions
/*! 
   \brief Contém os métodos para cada instrução e informações necessárias
         a execução.
 */
class Instructions{
public:
    std::stack<Frame>           frames;  /*!< Pilha de frames */
    std::vector<ClassFile*>     classes; /*!< Vetor de classes */
    std::vector<instrFunction>  instrs;  /*!< vetor de ponteiros para os métodos das instruções */
    //! heap
    /*! O heap é a área de dados de tempo de execução a partir da qual a memória 
            para todas as instâncias de classe e matrizes é alocada.
    */ 
    std::vector<void*>          heap;  

    Instructions() {};
    //! Construtor
    /*!
    Define os atributos. Constrói o vetor de instruções.
    \param PC Contador de Programa
    \param frames pilha de frames
    \param classes pilha de classes
    \sa ClassFile, Frame
    */ 
    Instructions(ClassFile *classFile);
    
    /**
     * @brief Executa uma instrução.
     * 
     * @param opcode Opcode da instrução a ser executada.
     */
    void execInstr(u1 opcode);

    /**
     * @brief Adiciona um valor ao PC
     * 
     * @param value Valor a ser adicionado ao PC.
     */
    void addToPC(int value);

    void _nop();
    void _aconst_null();
    void _iconst_m1();
    void _iconst_0();
    void _iconst_1();
    void _iconst_2();
    void _iconst_3();
    void _iconst_4();
    void _iconst_5();
    void _lconst_0();
    void _lconst_1();
    void _fconst_0();
    void _fconst_1();
    void _fconst_2();
    void _dconst_0();
    void _dconst_1();
    void _bipush();
    void _sipush();
    void _ldc();
    void _ldc_w();
    void _ldc2_w();
    void _iload();
    void _lload();
    void _fload();
    void _dload();
    void _aload();
    void _iload_0();
    void _iload_1();
    void _iload_2();
    void _iload_3();
    void _lload_0();
    void _lload_1();
    void _lload_2();
    void _lload_3();
    void _fload_0();
    void _fload_1();
    void _fload_2();
    void _fload_3();
    void _dload_0();
    void _dload_1();
    void _dload_2();
    void _dload_3();
    void _aload_0();
    void _aload_1();
    void _aload_2();
    void _aload_3();
    void _iaload();
    void _laload();
    void _faload();
    void _daload();
    void _aaload();
    void _baload();
    void _caload();
    void _saload();
    void _istore();
    void _lstore();
    void _fstore();
    void _dstore();
    void _astore();
    void _istore_0();
    void _istore_1();
    void _istore_2();
    void _istore_3();
    void _lstore_0();
    void _lstore_1();
    void _lstore_2();
    void _lstore_3();
    void _fstore_0();
    void _fstore_1();
    void _fstore_2();
    void _fstore_3();
    void _dstore_0();
    void _dstore_1();
    void _dstore_2();
    void _dstore_3();
    void _astore_0();
    void _astore_1();
    void _astore_2();
    void _astore_3();
    void _iastore();
    void _lastore();
    void _fastore();
    void _dastore();
    void _aastore();
    void _bastore();
    void _castore();
    void _sastore();
    void _pop();
    void _pop2();
    void _dup();
    void _dup_x1();
    void _dup_x2();
    void _dup2();
    void _dup2_x1();
    void _dup2_x2();
    void _swap();
    void _iadd();
    void _ladd();
    void _fadd();
    void _dadd();
    void _isub();
    void _lsub();
    void _fsub();
    void _dsub();
    void _imul();
    void _lmul();
    void _fmul();
    void _dmul();
    void _idiv();
    void _ldiv();
    void _fdiv();
    void _ddiv();
    void _irem();
    void _lrem();
    void _frem();
    void _drem();
    void _ineg();
    void _lneg();
    void _fneg();
    void _dneg();
    void _ishl();
    void _lshl();
    void _ishr();
    void _lshr();
    void _iushr();
    void _lushr();
    void _iand();
    void _land();
    void _ior();
    void _lor();
    void _ixor();
    void _lxor();
    void _iinc();
    void _i2l();
    void _i2f();
    void _i2d();
    void _l2i();
    void _l2f();
    void _l2d();
    void _f2i();
    void _f2l();
    void _f2d();
    void _d2i();
    void _d2l();
    void _d2f();
    void _i2b();
    void _i2c();
    void _i2s();
    void _lcmp();
    void _fcmpl();
    void _fcmpg();
    void _dcmpl();
    void _dcmpg();
    void _ifeq();
    void _ifne();
    void _iflt();
    void _ifge();
    void _ifgt();
    void _ifle();
    void _if_icmpeq();
    void _if_icmpne();
    void _if_icmplt();
    void _if_icmpge();
    void _if_icmpgt();
    void _if_icmple();
    void _if_acmpeq();
    void _if_acmpne();
    void _goto();
    void _jsr();
    void _ret();
    void _tableswitch();
    void _lookupswitch();
    void _ireturn();
    void _lreturn();
    void _freturn();
    void _dreturn();
    void _areturn();
    void _return();
    void _getstatic();
    void _putstatic();
    void _getField();
    void _putfield();
    void _invokevirtual();
    void _invokeSpecial();
    void _invokestatic();
    //void _invokeinterface();
    //void _invokdynamic();
    void _new();
    void _newarray();
    void _anewarray();
    void _arraylength();
    void _athrow();
    void _checkcast();
    void _instanceof();
    void _monitorenter();
    void _monitorexit();
    void _wide();
    void _multianewarray();
    void _ifnull();
    void _ifnonnull();
    void _goto_w();
    void _jsr_w();
};


#endif