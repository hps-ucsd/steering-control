#include <Gyro.hpp>

#include <fstream>
#include <sstream>

int stoi(const std::string& s)
{
	std::istringstream str(s);
	int i;
	str >> i;
	return i;
}

Gyro::Gyro(std::string filename)
{
	std::fstream in(filename);
	std::string str;
	while (in >> str)
	{
		data.push(stoi(str));
	}
}

short Gyro::readY()
{
	if (data.size() == 0) return 0;

	short value = data.front();
	data.pop();
	return value;
}

