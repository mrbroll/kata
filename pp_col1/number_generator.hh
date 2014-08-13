#include <string>

#ifndef _NUMBER_GENERATOR_HH
#define _NUMBER_GENERATOR_HH

class NumberGenerator {
public:
static NumberGenerator *Instance(void);
int generate(std::string fileName, size_t max = 10000000, size_t count = 1000000, size_t uniqueness = 1);

private:
NumberGenerator(void){};
static NumberGenerator *_instance;
};

#endif
