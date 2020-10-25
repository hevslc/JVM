
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
	uint64_t l = ((long)highBytes << 32) | (long)lowBytes;
	int s = ((l >> 63) == 0) ? 1 : -1;
	int e = (l >> 52) & 0x7ffL;
	long m = (e == 0) ? ((l & 0xfffffffffffffL) << 1) : ((l & 0xfffffffffffffL) | 0x10000000000000L);
	double v = (s*m*pow(2, e-1075));
	if(l == 0x7ff0000000000000L) return std::numeric_limits<double>::infinity();
	else if(l ==  0xfff0000000000000L) return -std::numeric_limits<double>::infinity();
	else return v;
}

long getLong(u4 highBytes, u4 lowBytes){
	return ((long)highBytes << 32) | (long)lowBytes;
}

int getInt(u4 bytes){
	return (int)bytes;
}

bool getBool(u4 bytes){
	return (bool)bytes;

}
