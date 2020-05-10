#include "GateFactory.h"

GateFactory::GateFactory()
{
}

Gate* GateFactory::createGate(EnumType type)
{
	switch (type)
	{
    case AND:
        return new AndGate(AND);
    case NAND:
        return nullptr;
    case OR:
        return new OrGate(OR);
    case NOR:
        return nullptr;
    case NOT:
        return nullptr;
    case XOR:
        return new XorGate(XOR);
    default:
        return nullptr;
	}
}
