#pragma once
#include <vector>

class InputGenerator
{
public:
	InputGenerator();
	void setBits(size_t bits);
	void generate();
	std::vector<bool> getInput(size_t index);
private:
	std::vector<bool> generate(size_t index, size_t bit);
private:
	size_t bits;
	std::vector<std::vector<bool>> gen_matrix;
};

