#include "bit_vector_2pass.hh"
#include <fstream>
#include <iostream>
#include <string>

BitVector *BitVector2Pass::_instance = NULL;

BitVector2Pass::BitVector2Pass(size_t length)
{
    _instance = BitVector::Instance(length / 2);
    _pass = 0;
}
