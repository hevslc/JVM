#include "reader.h"

int aux;

u1* r1(std::ifstream& f){
	u1 *c = new u1;
	f.read((char *)c, sizeof(u1));
	return c;
}
