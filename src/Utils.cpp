
#include "Utils.h"

float getFloat(u4 bytes){
	int s = ((bytes >> 31) == 0) ? 1 : -1;
	int e = (bytes >> 23) & 0xff;
	int m = (e == 0) ? (bytes & 0x7fffff) << 1 : (bytes & 0x7fffff) | 0x800000;
	float v = s*m*pow(2, exp(1)-150);
	if(bytes == 0x7f800000) return std::numeric_limits<float>::infinity();
	else if(bytes ==  0xff800000) return -std::numeric_limits<float>::infinity();
	else return v;
}

double getDouble(u4 highBytes, u4 lowBytes){
	uint64_t hb = highBytes;
	uint64_t l = (hb << 32) | (long)lowBytes;
	return reinterpret_cast<double&>(l);
}

long getLong(u4 highBytes, u4 lowBytes){
	uint64_t hb = highBytes;
	uint64_t l = (hb << 32) | (long)lowBytes;
	return reinterpret_cast<long&>(l);
}

int getInt(u4 bytes){
	return (int)bytes;
}

bool getBool(u4 bytes){
	return (bool)bytes;

}
