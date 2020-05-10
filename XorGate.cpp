#include "XorGate.h"

XorGate::XorGate(EnumType type) : Gate(type)
{
}

void XorGate::execute()
{
	wires[0]->setValue(wires[1]->getValue());
	for (size_t i = 0; i < wires.size(); ++i)
	{
		wires[0]->setValue(wires[0]->getValue() xor wires[i]->getValue());
	}
}

Wire* XorGate::getOutput()
{
	return wires[0];
}

void XorGate::AddWire(Wire* wire)
{
	wires.push_back(wire);
}

void XorGate::setValues(wire_table table, size_t pos)
{
	for (size_t i = 1; i < wires.size(); ++i)
	{
		wires[i]->setValue(table[wires[i]->getName()][pos]);
	}
}


