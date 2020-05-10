#include "InputGenerator.h"

InputGenerator::InputGenerator()
{
}

void InputGenerator::setBits(size_t bits)
{
	this->bits = bits;
}

void InputGenerator::generate()
{
	for (size_t i = 0; i < bits; ++i)
	{
		gen_matrix.push_back(generate(i + 1, bits));
	}
}

std::vector<bool> InputGenerator::getInput(size_t index)
{
	return gen_matrix[index];
}

std::vector<bool> InputGenerator::generate(size_t index, size_t bit)
{
	std::vector<bool> v;
	size_t count = (size_t)pow(2, bit) / (size_t)pow(2, bit - index + 1);
	for (size_t i = 0; i < count; ++i)
	{
		v.insert(v.end(), (size_t)pow(2, bit - index), 0);
		v.insert(v.end(), (size_t)pow(2, bit - index), 1);
	}
	return v;
}
