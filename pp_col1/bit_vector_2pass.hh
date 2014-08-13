#include "bit_vector.hh"
#include <string>

#ifndef _BIT_VECTOR_2PASS_HH
#define _BIT_VECTOR_2PASS_HH

class BitVector2Pass : public BitVector
{
public:
~BitVector(void);
using BitVector::Instance;
int hydrate(std::string fileName std::string tempFileName);
int writeBack(std::string fileName std::string tempFileName);

private:
BitVector2Pass(size_t length = 0);
static BitVector *_instance;
static int _pass;
};
#endif
