#include "WireFactory.h"

WireFactory::WireFactory()
{
}

Wire* WireFactory::createWire(std::string name)
{
	return new Wire(name);
}
