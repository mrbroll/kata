// This is a specialized bit vector implementation for column 1 of programming pearls 2nd ed
#include <string>
#include <fstream>

#ifndef _BIT_VECTOR_HH
#define _BIT_VECTOR_HH

// singleton class
class BitVector {
public:
~BitVector(void);
static BitVector *Instance(void);
int hydrate(std::string fileName);

private:
BitVector(void) {};
BitVector(BitVector const&) {};
BitVector* operator=(BitVector const&) {};
static *BitVector _instance;

char *_vectorData;

static const int _length = 1000000;
static const char _bitMask = 0x01;

int getBit(int index);
int setBit(int index);
int clearBit(int index);
};

#endif
