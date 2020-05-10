//#include "Header.h"
//#include "Compiler.h"

#include "Simulator.h"

int main()
{
	Simulator* ptr = new Simulator("netlist.txt");

	ptr->startSimulation();
	ptr->printResults();

	return 0;
}


