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

int NumberGenerator::generate(std::string fileName, size_t max, size_t count, size_t uniqueness)
{
    size_t *checkVector = (size_t *)calloc(max, sizeof(size_t));

    if (!checkVector)
        return 1;

    std::ofstream numberFile;
    numberFile.open(fileName);

    for (int i = 0; i < count; i++)
    {
        int randomValue = abs(rand()) % max;
        if (checkVector[randomValue] == uniqueness) {
            i++;
        } else {
            numberFile << randomValue << std::endl;
            checkVector[randomValue]++;
        }
    }

    free(checkVector);

    numberFile.close();

    return 0;
}

