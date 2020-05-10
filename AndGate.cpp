#include "AndGate.h"

AndGate::AndGate(EnumType type): Gate(type)
{
}

void AndGate::execute()
{
	wires[0]->setValue(wires[1]->getValue());
	for (size_t i = 0; i < wires.size(); ++i)
	{
		wires[0]->setValue(wires[0]->getValue() and wires[i]->getValue());
	}
}

Wire* AndGate::getOutput()
{
	return wires[0];
}

void AndGate::AddWire(Wire* wire)
{
	wires.push_back(wire);
}

void AndGate::setValues(wire_table table, size_t pos)
{
	for (size_t i = 1; i < wires.size(); ++i)
	{
		wires[i]->setValue(table[wires[i]->getName()][pos]);
	}
}

