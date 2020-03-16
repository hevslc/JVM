#include "reader.h"

int main(int argc, char const *argv[]){
	std::ifstream f;
	if(argc > 1)  f.open(argv[1], std::ios::binary);
	if(!f || argc == 1){
		std::cout << "Argumento não passado ou Arquivo não abriu.\n";
		return 0;
	}


	u1 *c = new u1;
	c = r1(f);

	std::cout << std::hex << (int)*c << std::endl;
	return 0;
}