#pragma once
#include "Gate.h"
#include <iostream>

class XorGate :public Gate
{
public:
	XorGate(EnumType type);
	void execute();
	Wire* getOutput();
	void AddWire(Wire* wire);
	void setValues(wire_table table, size_t pos);
	std::vector<Wire*> wires;
};
