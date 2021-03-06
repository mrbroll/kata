#include "bit_vector.hh"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

BitVector *BitVector::_instance = NULL;

BitVector::BitVector(size_t length) :  _length(length), _vectorData(NULL) {}

BitVector::~BitVector(void)
{
    if (_vectorData)
        free(_vectorData);

    _vectorData = NULL;
    _instance = NULL;
    _length = 0;
}


BitVector *BitVector::Instance(size_t length)
{
    if (!_instance)
        _instance = new BitVector(length);

    return _instance;
}

int BitVector::sortFile(std::string fileName)
{
    if (!_vectorData) {
        std::ifstream numberFile;
        numberFile.open(fileName);
        std::string line;

        size_t vectorSizeInBytes = (_length / 8) + 1; // ensure we have enough bits for our vector

        _vectorData = (char *)calloc(vectorSizeInBytes, sizeof(char));

        if (!_vectorData) {
            std::cout << "Dude, wtf. How did you run out of memory?!" << std::endl;
            return 1;
        }

        while(std::getline(numberFile, line))
        {
            int number = atoi(line.c_str());
            setBit(number);
        }

        numberFile.close();

        std::ofstream outputFile;
        outputFile.open(fileName);

        for (int i = 0; i < _length; ++i)
        {
            if (getBit(i))
                outputFile << i << std::endl;
        }

        outputFile.close();

        delete this;
    }

    return 0;
}

int BitVector::getBit(int index)
{
    return *(_vectorData + (index / 8)) & (_bitMask << (index % 8));
}

void BitVector::setBit(int index)
{
    *(_vectorData + (index / 8)) |= (_bitMask << (index % 8));
}

void BitVector::clearBit(int index)
{
    *(_vectorData + (index / 8)) &= ~(_bitMask << (index % 8));
}
