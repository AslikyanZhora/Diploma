#include "Compiler.h"

Compiler::Compiler(std::string path): 
		parser(new Parser(path))
{
}

void Compiler::Compile(wire_table& table,
	std::vector<Gate*>& gates, std::vector<std::string>& inputs)
{
	setInstructions();

	for (auto item : instructions)
	{
		CompileInstruction(item, table, gates, inputs);
	}
}


void Compiler::setInstructions()
{
	parser->setInstructions();
	instructions = parser->getInstructions();

}

void Compiler::CompileInstruction(Instruction* instr, wire_table& table,
	std::vector<Gate*>& gates, std::vector<std::string>& inputs)
{
	std::vector<std::string> variables = instr->getVariables();

	switch (instr->getType())
	{
	case INVALID:
		break;
	case INPUT:
		inputs.push_back(variables[0]);
		table[variables[0]] = std::vector<bool>();
		break;
	case OUTPUT:
	case WIRE:
		table[variables[0]] = std::vector<bool>();
		break;
	case AND:
		gates.push_back(createGate(instr));
		break;
	case NAND:
		break;
	case OR:
		gates.push_back(createGate(instr));
		break;
	case NOR:
		break;
	case NOT:
		break;
	case XOR:
		gates.push_back(createGate(instr));
		break;
	default:
		break;
	}
}

Gate* Compiler::createGate(Instruction* instr)
{
	WireFactory* wirefactory = new WireFactory();
	GateFactory* gateFactory = new GateFactory();
	Gate* gate = gateFactory->createGate(instr->getType());

	for (size_t i = 0; i < instr->getVariables().size(); ++i)
	{
		gate->AddWire(wirefactory->createWire(instr->getVariables()[i]));
	}

	delete gateFactory;
	delete wirefactory;

	return gate;
}
