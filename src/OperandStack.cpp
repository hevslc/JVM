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

short Operands::popShort() {
	Slot slot = top();
	pop();
	return getShort(slot.value);
}

int8_t Operands::popByte() {
	Slot slot = top();
	pop();
	return getByte(slot.value);
}

char Operands::popChar() {
	Slot slot = top();
	pop();
	return getChar(slot.value);
}

void Operands::pushLong(long l){
	u8 v = reinterpret_cast<u8&>(l);
	u4 high = u4(v >> 32);
	u4 low = u4(v & 0XFFFFFFFF);
	push(Slot(SlotType::LONG, low));
	push(Slot(SlotType::LONG, high));
}

void Operands::pushDouble(double d){
	u8 v = reinterpret_cast<u8&>(d);
	u4 high = u4(v >> 32);
	u4 low = u4(v & 0XFFFFFFFF);
	push(Slot(SlotType::DOUBLE, low));
	push(Slot(SlotType::DOUBLE, high));
}

void Operands::pushU8(SlotType type, u8 value) {
	u4 high = (u4)(value >> 32);
	u4 low = (u4)(value & 0xFFFFFFFF);
	push(Slot(type, low));
	push(Slot(type, high));
}

char* Operands::popString() {
	Slot slot = top();
	pop();
	return slot.ref.str;
}