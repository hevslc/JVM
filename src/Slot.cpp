#include "Slot.h"

Slot::Slot(SlotType type, u4 value)
{
    this->type = type;
    this->value = value;
}

u4 Slot::getHighd(double d){
    u8 v = reinterpret_cast<u8&>(d);
    return u4(v >> 32);
}

u4 Slot::getLowd(double d){
    u8 v = reinterpret_cast<u8&>(d);
    return u4((v & 0X0000FFFF) << 32);
}

u4 Slot::getHighd(long d){
    u8 v = reinterpret_cast<u8&>(d);
    return u4(v >> 32);
}

u4 Slot::getLowd(long d){
    u8 v = reinterpret_cast<u8&>(d);
    return u4((v & 0X0000FFFF) << 32);
}