#ifndef READER_H
#define READER_H

#include "definitions.h"

u1 r1(std::ifstream& f);
u2 r2(std::ifstream& f);
u4 r4(std::ifstream& f);

void reading(ClassFile *classFile, std::ifstream& f);

#endif