#pragma once
#include <string>
#include "Type.h"

class Wire
{
public:
	Wire();
	Wire(std::string name);
	Wire(std::string name, bool value, EnumType type);
	std::string getName();
	void setName(std::string name);
	bool getValue();
	void setValue(bool value);
	EnumType getType();
	void setType(EnumType type);
private:
	std::string name;
	bool value;
	EnumType type;
};