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
	Slot slot = top();
	pop();	
	return getInt(slot.value);
}
bool Operands::popBool(){
	Slot slot = top();
	pop();
	return getBool(slot.value);
}

void Operands::pushLong(long l){
	u8 v = reinterpret_cast<u8&>(l);
	u4 high = u4(v >> 32);
	u4 low = u4((v & 0X0000FFFF) << 32);
	push(Slot(SlotType::LONG, low));
	push(Slot(SlotType::LONG, high));
}

void Operands::pushDouble(double d){
	u8 v = reinterpret_cast<u8&>(d);
	u4 high = u4(v >> 32);
	u4 low = u4((v & 0X0000FFFF) << 32);
	push(Slot(SlotType::DOUBLE, low));
	push(Slot(SlotType::DOUBLE, high));
}