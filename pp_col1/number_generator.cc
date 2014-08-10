#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    int maxValue = 10000000;
    int numberCount = 1000000;
    std::ifstream inNumberFile;
    inNumberFile.open("phone_numbers.dat");
    std::string line;
    if (std::getline(inNumberFile, line)) {
        std::cout << "file already created, aborting" << std::endl;
        inNumberFile.close();
        return 1;
    }

    std::ofstream numberFile;
    numberFile.open("phone_numbers.dat");


    for (int i = 0; i < numberCount; ++i)
    {
        int randomValue = rand() % maxValue;
        numberFile << randomValue << std::endl;
    }

    numberFile.close();

    return 0;
}
