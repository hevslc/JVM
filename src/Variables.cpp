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