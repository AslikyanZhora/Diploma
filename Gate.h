#pragma once
#include "Wire.h"
#include <vector>
#include <map>
#include <string>

typedef std::map<std::string, std::vector<bool>> wire_table;

class Gate
{
public:
	Gate(EnumType type);
	virtual ~Gate();
	virtual void execute() = 0;
	virtual Wire* getOutput() = 0;
	virtual void AddWire(Wire* wire) = 0;
	virtual void setValues(wire_table table, size_t pos) = 0;
};

