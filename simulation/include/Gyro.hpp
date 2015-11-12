#pragma once

#ifndef GYRO_HPP
#define GYRO_HPP

#include <string>
#include <queue>

class Gyro
{
public:
	Gyro(std::string filenameIn);
	short readY();
private:
	std::queue<short> data;
};

#endif
