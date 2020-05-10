#include "OrGate.h"

OrGate::OrGate(EnumType type) : Gate(type)
{
}

void OrGate::execute()
{
	wires[0]->setValue(wires[1]->getValue());
	for (size_t i = 0; i < wires.size(); ++i)
	{
		wires[0]->setValue(wires[0]->getValue() or wires[i]->getValue());
	}
}

Wire* OrGate::getOutput()
{
	return wires[0];
}

void OrGate::AddWire(Wire* wire)
{
	wires.push_back(wire);
}

void OrGate::setValues(wire_table table, size_t pos)
{
	for (size_t i = 1; i < wires.size(); ++i)
	{
		wires[i]->setValue(table[wires[i]->getName()][pos]);
	}
}

