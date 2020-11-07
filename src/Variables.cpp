#include "Variables.h"

float Variables::asFloat(int position)
{
    Slot slot = at(position);
    return getFloat(slot.value);
}

double Variables::asDouble(int position)
{
    Slot slot1 = at(position);
    Slot slot2 = at(position + 1);
    return getDouble(slot1.value, slot2.value);
}

int Variables::asInt(int position)
{
    Slot slot = at(position);
    return getInt(slot.value);
}

long Variables::asLong(int position)
{
    Slot slot1 = at(position);
    Slot slot2 = at(position + 1);
    return getLong(slot1.value, slot2.value);
}

bool Variables::asBool(int position)
{
    Slot slot = at(position);
    return getBool(slot.value);
}

void Variables::putLong(long l, u1 position){
	u8 v = reinterpret_cast<u8&>(l);
	u4 high = u4(v >> 32);
	u4 low = u4(v & 0X0000FFFF);
	at(position) = Slot(SlotType::LONG, high);
	at(position+1) = Slot(SlotType::LONG, low);
}

void Variables::putDouble(double d, u1 position){
	u8 v = reinterpret_cast<u8&>(d);
	u4 high = u4(v >> 32);
	u4 low = u4(v & 0X0000FFFF);
	at(position) = Slot(SlotType::DOUBLE, high);
	at(position+1) = Slot(SlotType::DOUBLE, low);
}

void Variables::putU8(SlotType type, u8 value, u1 position) {
    u4 high = u4(value >> 32);
    u4 low = u4(value & 0XFFFFFFFF);
    at(position) = Slot(type, high);
    at(position + 1) = Slot(type, low);
}