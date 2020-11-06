#include "OperandStack.h"

float Operands::popFloat(){
	if(empty()){
		std::cout << "Pilha de operandos vazia!" << std::endl;
	}
	Slot slot = top();
	pop();
	return getFloat(slot.value);
}

double Operands::popDouble(){
	if(empty()){
		std::cout << "Pilha de operandos vazia!" << std::endl;
	}
	Slot slot1 = top();
	pop();
	Slot slot2 = top();
	pop();
	return getDouble(slot1.value, slot2.value);
}
long Operands::popLong(){
	if(empty()){
		std::cout << "Pilha de operandos vazia!" << std::endl;
	}
	Slot slot1 = top();
	pop();
	//std::cout << "slot1: " << slot1.value << std::endl;
	Slot slot2 = top();
	pop();
	//std::cout << "slot2: " << slot2.value << std::endl;

	return getLong(slot1.value, slot2.value);
}
int Operands::popInt(){
	if(empty()){
		std::cout << "Pilha de operandos vazia!" << std::endl;
	}
	Slot slot = top();
	pop();	
	return getInt(slot.value);
}
bool Operands::popBool(){
	if(empty()){
		std::cout << "Pilha de operandos vazia!" << std::endl;
	}
	Slot slot = top();
	pop();
	return getBool(slot.value);
}

void Operands::pushLong(long l){
	u8 v = reinterpret_cast<u8&>(l);
	u4 high = u4(v >> 32);
	u4 low = u4((v & 0X0000FFFF));
	//std::cout << "v: " << v << std::endl;
	//std::cout << "high: " << high << std::endl;
	//std::cout << "low: " << low << std::endl;
	push(Slot(SlotType::LONG, low));	
	push(Slot(SlotType::LONG, high));
	
}

void Operands::pushDouble(double d){
	u8 v = reinterpret_cast<u8&>(d);
	u4 high = u4(v >> 32);
	u4 low = u4((v & 0X0000FFFF));
	//std::cout << "v: " << v << std::endl;
	//std::cout << "high: " << high << std::endl;
	//std::cout << "low: " << low << std::endl;
	push(Slot(SlotType::DOUBLE, low));
	push(Slot(SlotType::DOUBLE, high));
}

