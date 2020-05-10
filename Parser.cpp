#include "Parser.h"

Parser::Parser(std::string path): 
		type(new Type()),
		path(path)
{
}

Parser::~Parser()
{
	delete type;
	type = nullptr;

	for (auto i : instructions)
	{
		delete i;
		i = nullptr;
	}
}

void Parser::setPath(std::string path)
{
	this->path = path;
}

std::vector<Instruction*> Parser::getInstructions()
{
	return this->instructions;
}

void Parser::setInstructions()
{
	std::ifstream file(path);
	std::string line;

	while (std::getline(file, line))
	{
		if (line.size() == 0)
		{
			continue;
		}
		instructions.push_back(ParseInstruction(line));
	}
}

std::vector<std::string> Parser::Tockenize(std::string line)
{
	std::istringstream iss(line);
	std::vector<std::string> results(std::istream_iterator<std::string>{iss},
		std::istream_iterator<std::string>());

	return results;
}

std::vector<std::string> Parser::ParseGate(std::string line)
{
	line.erase(0, line.find('(') + 1);
	line.erase(line.find(')'));
	std::replace(line.begin(), line.end(), ',', ' ');
	std::vector<std::string> result = Tockenize(line);

	return result;
}

EnumType Parser::ParseType(std::string type)
{
	return this->type->type_map[type];
}

std::vector<std::string> Parser::ParseValue(std::string _type, std::string value)
{
	std::vector<std::string> wire;
	switch (type->type_map[_type])
	{
	case INVALID:
		return std::vector<std::string>();
	case INPUT:
	case OUTPUT:
	case WIRE:
		value.pop_back();
		wire.push_back(value);
		return wire;
	default:
		std::vector<std::string> result = ParseGate(value);
		return result;
	}
}

Instruction* Parser::ParseInstruction(std::string line)
{
	Instruction* instruction = new Instruction();

	std::vector<std::string> command = Tockenize(line);

	instruction->setType(ParseType(command[0]));
	instruction->setVariables(ParseValue(command[0], command[1]));

	return instruction;

}

