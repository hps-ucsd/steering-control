#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <cmath>

void generateData(int numSamples)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int realHeading = 0;
    int noise = 500;

    std::normal_distribution<double> dist(realHeading, noise);
    for (int i = 0; i < numSamples; i++) {
        std::cout << round(dist(gen)) << std::endl;
    }
}