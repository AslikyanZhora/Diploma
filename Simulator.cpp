#include "Simulator.h"

Simulator::Simulator(std::string path): 
	compiler(new Compiler(path)),
    inputGenerator(new InputGenerator())
{
	compiler->Compile(table, gates, inputs);
	inputGenerator->setBits(inputs.size());

}

void Simulator::startSimulation()
{
	size_t size = (size_t)pow(2, inputs.size());

	for (size_t i = 0; i < size; ++i)
	{
		execute(i);
	}

}

void Simulator::printResults()
{
	for (auto i : table)
	{
		std::cout << i.first << ":  ";
		for (auto j : i.second)
		{
			std::cout << j << "  ";
		}
		std::cout << std::endl;
	}
}

void Simulator::generateInputs()
{
	inputGenerator->generate();

	size_t i = 0;

	for (auto input: inputs)
	{
		table[input] = inputGenerator->getInput(i++);
	}
}

void Simulator::execute(size_t pos)
{
	generateInputs();
	std::string name = "";
	bool value = false;
	for (auto gate: gates)
	{
		gate->setValues(table, pos);
		gate->execute();

		name = gate->getOutput()->getName();
		value = gate->getOutput()->getValue();

		table[name].push_back(value);
	}

}
