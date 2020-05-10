#pragma once

#include <map>
#include <string>

enum EnumType
{
	INVALID, INPUT, OUTPUT, WIRE, AND, NAND, OR, NOR, NOT, XOR
};

struct Type
{
	Type()
	{
		type_map["input"] = INPUT;
		type_map["output"] = OUTPUT;
		type_map["wire"] = WIRE;
		type_map["and"] = AND;
		type_map["nand"] = NAND;
		type_map["or"] = OR;
		type_map["nor"] = NOR;
		type_map["not"] = NOT;
		type_map["xor"] = XOR;
	}

	std::map<std::string, EnumType> type_map;
};