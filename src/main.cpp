#include "ClassFile.h"
#include "Interpreter.h"

int main(int argc, char const *argv[]){
	std::ifstream f;
	if(argc > 1)  f.open(argv[1], std::ios::binary);
	if(!f || argc == 1){
		std::cout << "Argumento não passado ou Arquivo não abriu.\n";
		return 0;
	}

	ClassFile classFile(f);

	if(argc == 3){
		if(atoi(argv[2]) == 0 ){
	  		classFile.print(interminal, std::string(argv[1]));
	  		classFile.print(infile, std::string(argv[1]));
		}
	}
	else{			
		Interpreter interpreter(&classFile);
		interpreter.execute();
	}

	f.close();
	

	return 0;	
}
