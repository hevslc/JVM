#include "OperandStack.h"

float Operands::popFloat(){
	Slot slot = top();
	pop();
	return getFloat(slot.value);
}

double Operands::popDouble(){
	Slot slot1 = top();
	pop();
	Slot slot2 = top();
	pop();
	return getDouble(slot1.value, slot2.value);
}
long Operands::popLong(){
	Slot slot1 = top();
	pop();
	Slot slot2 = top();
	pop();
	return getLong(slot1.value, slot2.value);
}
int Operands::popInt(){
	if(empty()){
		std::cout << "Vazio!" << std::endl;
	}
	Slot slot = top();
	pop();	
	return getInt(slot.value);
}
bool Operands::popBool(){
	Slot slot = top();
	pop();
	return getBool(slot.value);
}