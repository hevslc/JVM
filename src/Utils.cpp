
#include "Utils.h"

u8 highlowBytes(u4 highBytes, u4 lowBytes){
	u8 hb = highBytes;
	return (u8)(hb << 32) | lowBytes;	
}

float getFloat(u4 bytes){
	return reinterpret_cast<float&>(bytes);
}

double getDouble(u4 highBytes, u4 lowBytes){
	u8 v = highlowBytes(highBytes, lowBytes);
	return reinterpret_cast<double&>(v);
}

long getLong(u4 highBytes, u4 lowBytes){
	u8 v = highlowBytes(highBytes, lowBytes);
	return reinterpret_cast<long&>(v);
}

int getInt(u4 bytes){
	return reinterpret_cast<int&>(bytes);
}

bool getBool(u4 bytes){
	return reinterpret_cast<bool&>(bytes);

}

short getShort(u4 bytes) {
	uint16_t v = uint16_t(bytes);
	return reinterpret_cast<u2&>(v);
}

int8_t getByte(u4 bytes) {
	return bytes;
}

char getChar(u4 bytes) {
	return bytes;
}

u2 getIndex(u1 byte1, u1 byte2) {
	return ((u2)byte1 << 8) | byte2;
}

int16_t getBranchOffset(u1 high, u1 low) {
	u2 value = ((u2)high << 8) | low;
	return reinterpret_cast<int16_t&>(value);
}

u8 charPointerToU8(u1* str) {
	return reinterpret_cast<u8>(str);
}

char* u8ToCharPointer(u4 highBytes, u4 lowBytes) {
	return reinterpret_cast<char*>(highlowBytes(highBytes, lowBytes));
}
