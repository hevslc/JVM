#include "Frame.h"

Frame::Frame(ClassFile* classFile, MethodInfo* method):
method(method),
classFile(classFile)
{
    bytecode = method->attributes->at(0)->getCode();
}