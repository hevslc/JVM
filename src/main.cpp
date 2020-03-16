#include "reader_display.h"

int main(int argc, char const *argv[]){
	std::ifstream f;
	if(argc > 1)  f.open(argv[1], std::ios::binary);
	if(!f || argc == 1){
		std::cout << "Argumento não passado ou Arquivo não abriu.\n";
		return 0;
	}

	ClassFile *classFile = new ClassFile;
	reading(classFile, f);

	f.close();
	return 0;
}

