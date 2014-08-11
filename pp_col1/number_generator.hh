#include <string>

#ifndef _NUMBER_GENERATOR_HH
#define _NUMBER_GENERATOR_HH

class NumberGenerator {
public:
static NumberGenerator *Instance(void);
int generate(std::string fileName);

private:
NumberGenerator(void){};
static NumberGenerator *_instance;
};

#endif
