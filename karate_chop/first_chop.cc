// This is kata02 form codekata.com = binary search on an array of integers
// returning the index of the key, if found. -1 otherwise

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "first_chop.hh"

int FirstChop::m_chop(int key, size_t arraySize, int inputArray[])
{
    int retVal;

    if (inputArray) {
        int middle = arraySize/2;

        if (key == inputArray[middle]) {
            return middle;
        } else if (key < inputArray[middle]) { // key < inputArray[middle]
            int *newArray;
            newArray = (int *)malloc(middle*sizeof(int));
            memcpy(newArray, inputArray, middle*sizeof(int));
            retVal = m_chop(key, middle, newArray);
            free(newArray);
        } else if ((arraySize - 1) - middle) {
            int *newArray;
            newArray = (int *)malloc((arraySize - middle)*sizeof(int));
            memcpy(newArray, (inputArray + middle), (arraySize - middle)*sizeof(int));
            retVal = m_chop(key, (arraySize - middle), newArray);
            retVal += (retVal >= 0) ? middle : 0;
            free(newArray);
        } else {
            retVal = -1;
        }
    } else {
        retVal = -1;
    }

    return retVal;
}

void FirstChop::m_runTests(void)
{
    int testArray[10] = {-13, -5, -3, 0, 12, 14, 17, 92, 129, 328};

    int test0 = m_chop(0, 10, testArray);
    assert(test0 == 3);
    std::cout << "passed first test" << std::endl;

    int test1 = m_chop(92, 10, testArray);
    assert(test1 == 7);
    std::cout << "passed second test" << std::endl;

    // edge cases
    int test2 = m_chop(328, 10, testArray);
    assert(test2 == 9);
    std::cout << "passed third test" << std::endl;

    int test3 = m_chop(-13, 10, testArray);
    assert(test3 == 0);
    std::cout << "passed fourth test" << std::endl;

    int test4 = m_chop(999, 10, testArray);
    assert(test4 == -1);
    std::cout << "passed fifth test" << std::endl;

    int test5 = m_chop(13, 10, testArray);
    assert(test5 == -1);
    std::cout << "passed all tests. i am one step closer to a coding sensei" << std::endl;

    return;
}
