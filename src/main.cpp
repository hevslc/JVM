#include "ClassFile.h"
#include "Display.h"

int main(int argc, char const *argv[]){
	std::ifstream f;
	if(argc > 1)  f.open(argv[1], std::ios::binary);
	if(!f || argc == 1){
		std::cout << "Argumento não passado ou Arquivo não abriu.\n";
		return 0;
	}
	ClassFile *classFile = new ClassFile();		//Aloca a estrutura ClassFile
	classFile->reading(f);

	printClassFile(classFile);

	delete classFile;
	f.close();
	return 0;
}
