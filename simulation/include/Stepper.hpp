#pragma once

#ifndef STEPPER_HPP
#define STEPPER_HPP

#include <string>
#include <fstream>
#include <queue>

class Stepper
{
public:
	Stepper(std::string filenameOut);
	~Stepper();

	void move(int offset);
private:
	std::string filename;
	std::fstream out;

	std::queue<short> position;
};

#endif