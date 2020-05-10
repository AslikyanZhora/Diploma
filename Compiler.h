#pragma once
#include "Parser.h"
#include "Gate.h"
#include "GateFactory.h"
#include "WireFactory.h"

class Compiler
{
public:
	Compiler(std::string path);

	void Compile(wire_table& table,
		std::vector<Gate*>& gates, std::vector<std::string>& inputs);
	
private:
	void setInstructions();
	void CompileInstruction(Instruction* instr, wire_table& table, 
		std::vector<Gate*>& gates, std::vector<std::string>& inputs);
	Gate* createGate(Instruction* instr);

private:
	Parser* parser;
	std::vector<Instruction*> instructions;
};

