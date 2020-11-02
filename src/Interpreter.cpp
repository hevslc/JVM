#include "Interpreter.h"

Interpreter::Interpreter(ClassFile classFile) : 
    classFile(classFile), instructions(classFile){
    instructions.execInstr(0); //teste
    
}

void Interpreter::execute(){
    MethodInfo* mthMain;
    for(auto mth : classFile.methods){
        if(!mth->name.compare("main([Ljava/lang/String;)V")){
            mthMain = mth;
            break;
        }
    }
    //std::cout << mthMain->name << std::endl;
}