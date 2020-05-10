#pragma once

#include "Gate.h"
#include <iostream>

class OrGate :public Gate
{
public:
	OrGate(EnumType type);
	void execute();
	Wire* getOutput();
	void AddWire(Wire* wire);
	void setValues(wire_table table, size_t pos);
	std::vector<Wire*> wires;
};


