#include "Frame.h"

Frame::Frame(ClassFile* classFile, MethodInfo* method):
variables(method->attributes->at(0)->getMaxLocals()),
method(method),
classFile(classFile)
{
    bytecode = method->attributes->at(0)->getCode();
}