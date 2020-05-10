#pragma once
#include "Gate.h"
#include "AndGate.h"
#include "OrGate.h"
#include "XorGate.h"


class GateFactory
{
public:
	GateFactory();
	Gate* createGate(EnumType type);
};

