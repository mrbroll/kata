#include "number_generator.hh"
#include <cmath>
#include <fstream>
#include <string>

NumberGenerator *NumberGenerator::_instance = NULL;

NumberGenerator *NumberGenerator::Instance(void)
{
    if (!_instance)
        _instance = new NumberGenerator();

    return _instance;
}

int NumberGenerator::generate(std::string fileName)
{
    int maxValue = 10000000;
    int numberCount = 1000000;

    std::ofstream numberFile;
    numberFile.open(fileName);

    for (int i = 0; i < numberCount; ++i)
    {
        int randomValue = abs(rand() % maxValue);
        numberFile << randomValue << std::endl;
    }

    numberFile.close();

    return 0;
}

