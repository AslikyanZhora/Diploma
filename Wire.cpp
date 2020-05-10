#include "Wire.h"

Wire::Wire(std::string name, bool value, EnumType type)
{
	this->name = name;
	this->value = value;
	this->type = type;
}

Wire::Wire()
{
}

Wire::Wire(std::string name)
{
	this->name = name;
}

std::string Wire::getName()
{
	return this->name;
}

void Wire::setName(std::string name)
{
	this->name = name;
}

bool Wire::getValue()
{
	return this->value;
}

void Wire::setValue(bool value)
{
	this->value = value;
}

EnumType Wire::getType()
{
	return this->type;
}

void Wire::setType(EnumType type)
{
	this->type = type;
}
