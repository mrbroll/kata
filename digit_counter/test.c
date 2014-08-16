#include "digit_counter.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    /*int testIntA = 231, testDigitA = 8;
    int testIntB = -1987, testDigitB = 5;
    int testIntC = 4387248, testDigitC = 2;     // return 1,000,000 + 4*100,000 + 4*10*
    int testIntD = 0, testDigitD = 9;           // return 0
    int testIntE = -3, testDigitE = 1;          // return 1
    int testIntF = 928, testDigitF = 38;        // return -1 for bad input*/


    printf("running tests...\n");
    int testIntA = 42;
    int testDigitA = 2;
    int testIntB = 231;
    int testDigitB = 3;
    int testIntC = -478;
    int testDigitC = 4;

    printf("Iterative function with N = %d, and Digit = %d...\n", testIntA, testDigitA);
    size_t countA = getCountIterative(testIntA, testDigitA);
    assert(countA == 15);
    printf("passed!\n");

    printf("Iterative function with N = %d, and Digit = %d...\n", testIntB, testDigitB);
    size_t countB = getCountIterative(testIntB, testDigitB);
    printf("count: %zd\n", countB);
    assert(countB == 45);
    printf("passed!\n");

    printf("Iterative function with N = %d, and Digit = %d...\n", testIntC, testDigitC);
    size_t countC = getCountIterative(testIntC, testDigitC);
    printf("count: %zd\n", countC);
    assert(countC == 177);
    printf("passed!\n");

    printf("all tests passed...\n");
    return 0;
}
