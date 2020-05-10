#pragma once
#include "Compiler.h"
#include "InputGenerator.h"

class Simulator
{
public:
	Simulator(std::string path);
	void startSimulation();
	void printResults();
private:
	void generateInputs();
	void execute(size_t pos);
private:
	Compiler* compiler;
	InputGenerator* inputGenerator;
	std::vector<std::string> inputs;
	wire_table table;
	std::vector<Gate*> gates;
};

