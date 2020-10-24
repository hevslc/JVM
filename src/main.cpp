#include "ClassFile.h"

int main(int argc, char const *argv[]){
	std::ifstream f;
	if(argc > 1)  f.open(argv[1], std::ios::binary);
	if(!f || argc == 1){
		std::cout << "Argumento não passado ou Arquivo não abriu.\n";
		return 0;
	}

	if(atoi(argv[2]) == 0 ){
		ClassFile classFile(f);

  		classFile.print(interminal, std::string(argv[1]));
  		classFile.print(infile, std::string(argv[1]));
	}
	if(atoi(argv[2]) == 1 ){
			std::cout << "Aqui vem a chamada da JVM..." << std::endl;
	}

	
	f.close();
	

	return 0;
}
