#include "bit_vector_2pass.hh"
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

BitVector2Pass *BitVector2Pass::_instance = NULL;

BitVector2Pass::BitVector2Pass(size_t length) : BitVector(length / 2)
{
    _length = length;
}

BitVector2Pass *BitVector2Pass::Instance(size_t length)
{
    if (!_instance)
        _instance = new BitVector2Pass(length);

    return _instance;
}

BitVector2Pass::~BitVector2Pass(void)
{
    _length = 0;
    _instance = NULL;
}

int BitVector2Pass::sortFile(std::string fileName, std::string tempFileName1, std::string tempFileName2)
{
    std::ifstream inputFile;
    inputFile.open(fileName);
    std::ofstream outputFile1;
    std::ofstream outputFile2;
    outputFile1.open(tempFileName1);
    outputFile2.open(tempFileName2);
    std::string line;

    while(getline(inputFile, line))
    {
        int value = atoi(line.c_str());
        if (value <= _length / 2)
            outputFile1 << line << std::endl;
        else
            outputFile2 << value - (_length / 2) <<std::endl;
    }

    inputFile.close();
    outputFile1.close();
    outputFile2.close();

    BitVector::Instance(_length / 2)->sortFile(tempFileName1);
    BitVector::Instance(_length / 2)->sortFile(tempFileName2);

    std::ofstream outputFile;
    inputFile.open(tempFileName1);
    outputFile.open(fileName);
    while(getline(inputFile, line))
    {
        outputFile << atoi(line.c_str()) << std::endl;
    }

    inputFile.close();

    inputFile.open(tempFileName2);
    while(getline(inputFile, line))
    {
        outputFile << atoi(line.c_str()) + (_length / 2) << std::endl;
    }

    inputFile.close();

    outputFile.close();
    remove(tempFileName1.c_str());
    remove(tempFileName2.c_str());

    return 0;
}
