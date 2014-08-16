// This is a specialized bit vector implementation for column 1 of programming pearls 2nd ed
#include <string>
#include <fstream>

#ifndef _BIT_VECTOR_HH
#define _BIT_VECTOR_HH

// singleton class
class BitVector {
public:
static BitVector *Instance(size_t length = 0);
int sortFile(std::string fileName);

protected:
BitVector(size_t length);
virtual ~BitVector(void);
static BitVector *_instance;
size_t _length;
static const char _bitMask = 0x01;
int getBit(int index);
void setBit(int index);
void clearBit(int index);

private:
char *_vectorData;
};

#endif
