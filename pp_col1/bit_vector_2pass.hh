#include "bit_vector.hh"
#include <string>

#ifndef _BIT_VECTOR_2PASS_HH
#define _BIT_VECTOR_2PASS_HH

class BitVector2Pass : protected BitVector
{
public:
static BitVector2Pass *Instance(size_t length = 0);
int sortFile(std::string fileName, std::string tempFileName1, std::string tempFileName2);

protected:
BitVector2Pass(size_t length = 0);
virtual ~BitVector2Pass(void);

private:
static BitVector2Pass *_instance;
};
#endif
