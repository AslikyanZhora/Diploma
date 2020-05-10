#pragma once

#include "Type.h"
#include <string>
#include <vector>

struct Instruction
{
	Instruction()
	{

	}

	void setType(EnumType _type)
	{
		type = _type;
	}

	EnumType getType()
	{
		return type;
	}

	void setVariables(std::vector<std::string> _variables)
	{
		variables = _variables;
	}

	std::vector<std::string> getVariables()
	{
		return variables;
	}

	EnumType type;
	std::vector<std::string> variables;
};