#include <Stepper.hpp>

Stepper::Stepper(std::string filenameOut)
	: out(filenameOut, std::fstream::out | std::fstream::trunc) 
{
	position.push(0);
}

Stepper::~Stepper()
{
	while (position.size() > 0)
	{
		out << position.front() << '\n';
		position.pop();
	}

	out.close();
}

void Stepper::move(int offset)
{
	short previousPos = position.front();
	short newPos = previousPos + offset;
	position.push(newPos);
}