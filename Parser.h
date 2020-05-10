#pragma once

#include "Instruction.h"
#include <string>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>
#include <iostream>
class Parser
{
public:
	Parser(std::string path);
	~Parser();
	void setPath(std::string path);
	std::vector<Instruction*> getInstructions();
	void setInstructions();
private:
	std::vector<std::string> Tockenize(std::string line);
	std::vector<std::string> ParseGate(std::string line);
	EnumType ParseType(std::string type);
	std::vector<std::string> ParseValue(std::string _type, std::string value);
	Instruction* ParseInstruction(std::string line);
private:
	std::vector<Instruction*> instructions;
	std::string path;
	Type* type;
};

