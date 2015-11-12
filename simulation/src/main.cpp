#include <iostream>
#include <fstream>
#include <string>

#include <Gyro.hpp>
#include <Stepper.hpp>

int pid(int setPoint, int sensor)
{
	int error = setPoint - sensor;

	return error;
}

int main()
{
	Gyro gyro("zero.txt");
	Stepper stepper("stepper_zero_out.txt");

	for (int i = 0; i < 10000; i++)
	{
		stepper.move(pid(0, gyro.readY()));
	}
}