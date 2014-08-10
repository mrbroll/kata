#include "bit_vector.hh"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

BitVector *BitVector::_instance = NULL;

BitVector::~BitVector(void)
{
    if (_vectorData)
        free(_vectorData);

    _vectorData = NULL;
}


BitVector *BitVector::Instance(void)
{
    if (!_instance)
        _instance = new BitVector();

    return _instance;
}

int BitVector::hydrate(std::string fileName)
{
    std::ifstream numberFile;
    numberFile.open(fileName);
    std::string line;
    if (!std::getline(numberFile, line)) {
        std::cout << "File " << fileName << " is empty. Aborting..." << std::endl;
        return 1;
    }

    size_t vectorSizeInBytes = (_length / sizeof(char)) + 1; // ensure we have enough bits for our vector

    _vectorData = (char *)malloc(vectorSizeInBytes);

    if (!_vectorData) {
        std::cout << "Dude, wtf. How did you run out of memory?!" << std::endl;
        return 1;
    }

    while(std::getline(numberFile, line, '\n')) 
    {
        int number = atoi(line.c_str());
        setBit(number);
    }

    return 0;
}

int BitVector::getBit(int index)
{
    if (!_vectorData)
        return 0;

    int offset = index / 8;
    int shift = index % 8;

    return *(_vectorData + offset) & (_bitMask << shift);
}

int BitVector::setBit(int index)
{
    if (!_vectorData)
        return 1;

    int offset = index / 8;
    int shift = index % 8;

    *(_vectorData + offset) |= (_bitMask << shift);
}

int BitVector::clearBit(int index)
{
    if (!_vectorData)
        return 1;

    int offset = index / 8;

    int shift = index % 8;

    *(_vectorData + offset) &= ~(_bitMask << shift);
}
