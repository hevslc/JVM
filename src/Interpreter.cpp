#include "Interpreter.h"

Interpreter::Interpreter(ClassFile* classFile) : 
    classFile(classFile), instructions(classFile){
}

void Interpreter::execute(){
    MethodInfo* mthMain;
    for(auto mth : classFile->methods){
        if(!(mth->name + mth->descriptor).compare("main([Ljava/lang/String;)V")){
            mthMain = mth;
            break;
        }
    }

    if (mthMain != nullptr) {
        instructions.frames.push(Frame(classFile, mthMain));

        while(!instructions.frames.empty()) {
            Frame top = instructions.frames.top();
            instructions.execInstr(top.bytecode[top.PC]);
        }
    }
    else {
        std::cout << "The class specified must have a main method" << std::endl;
    }
}