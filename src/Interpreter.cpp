#include "Interpreter.h"

Interpreter::Interpreter(ClassFile* classFile) : 
    classFile(classFile), instructions(classFile){
    //instructions.execInstr(0); //teste    
}

void Interpreter::execute(){
    MethodInfo* mthMain;
    for(auto mth : classFile->methods){
        if(!(mth->name + mth->descriptor).compare("main([Ljava/lang/String;)V")){
            mthMain = mth;
            break;
        }
    }
    
    AttributeInfo* code = (*mthMain->attributes)[0];
    instructions.frames.push(Frame(code->getCode()));

    //teste
    std::cout << std::showbase;
    std::cout << std::hex << (int)instructions.frames.top().bytecode[0] << std::endl;
}