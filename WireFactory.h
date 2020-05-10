#pragma once
#include "Wire.h"

class WireFactory
{
public:
	WireFactory();
	Wire* createWire(std::string name);
};

