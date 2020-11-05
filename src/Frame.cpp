#include "Frame.h"

Frame::Frame(MethodInfo* method):
method(method)
{
    bytecode = method->attributes->at(0)->getCode();
}