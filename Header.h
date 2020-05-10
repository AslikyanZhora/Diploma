#pragma once
#include <iostream>
#include "Parser.h"
#include "InputGenerator.h"
#include <map>
#include "AndGate.h"
#include "GateFactory.h"
#include "Compiler.h"

void print(std::vector<bool> v);
void testAndGate();

void testParser()
{
	Parser* obj = new Parser("netlist.txt");
	obj->setInstructions();
	std::vector<Instruction*> v = obj->getInstructions();

	for (auto ins : v)
	{
		std::cout << ins->type << ":";
		for (auto s : ins->variables)
		{
			std::cout << s << "  ";
		}
		std::cout << std::endl;
	}

	delete obj;
}

void testGenerator()
{
	InputGenerator* gen = new InputGenerator();
	gen->setBits(4);
	gen->generate();
	std::vector<bool> v = gen->getInput(0);
	print(v);
	v = gen->getInput(1);
	print(v);
	v = gen->getInput(2);
	print(v);
	v = gen->getInput(3);
	print(v);

	delete gen;
	gen = nullptr;
}

void print(std::vector<bool> v)
{
	for (auto i : v)
	{
		std::cout << i << "  ";
	}
	std::cout << std::endl;
}

void testAndGate()
{
	wire_table wire_map;
	InputGenerator* gen = new InputGenerator();
	gen->setBits(2);
	gen->generate();

	wire_map["a"] = gen->getInput(0);
	wire_map["b"] = gen->getInput(1);

	Wire* a = new Wire();
	a->setName("a");

	Wire* b = new Wire();
	b->setName("b");

	Wire* c = new Wire();
	c->setName("c");

	Wire* out = new Wire();
	out->setName("out");

	GateFactory* gf = new GateFactory();

	Gate* andGate = gf->createGate(AND);

	andGate->AddWire(out);
	andGate->AddWire(a);
	andGate->AddWire(b);

	for (size_t i = 0; i < 4; ++i)
	{
		andGate->setValues(wire_map, i);
		andGate->execute();
		out = andGate->getOutput();
		std::cout << out->getValue() << "  ";
	}
	std::cout << std::endl;
}
