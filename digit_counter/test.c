#include "digit_counter.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("running tests...\n");
    int testIntA = 42;
    int testDigitA = 2;
    int testIntB = 231;
    int testDigitB = 3;
    int testIntC = -478;
    int testDigitC = 4;

    size_t count;


    printf("Iterative function with N = %d, and Digit = %d...\n", testIntA, testDigitA);
    count = getCountIterative(testIntA, testDigitA);
    assert(count == 15);
    printf("passed!\n");

    printf("Recursive function with N = %d, and Digit = %d...\n", testIntA, testDigitA);
    count = getCountRecursive(testIntA, testDigitA, 0);
    printf("Count: %zd\n", count);
    assert(count == 15);
    printf("passed!\n");

    printf("Iterative function with N = %d, and Digit = %d...\n", testIntB, testDigitB);
    count = getCountIterative(testIntB, testDigitB);
    printf("count: %zd\n", count);
    assert(count == 45);
    printf("passed!\n");

    printf("Recursive function with N = %d, and Digit = %d...\n", testIntB, testDigitB);
    count = getCountRecursive(testIntB, testDigitB, 0);
    printf("count: %zd\n", count);
    assert(count == 45);
    printf("passed!\n");

    printf("Iterative function with N = %d, and Digit = %d...\n", testIntC, testDigitC);
    count = getCountIterative(testIntC, testDigitC);
    printf("count: %zd\n", count);
    assert(count == 177);
    printf("passed!\n");

    printf("Recursive function with N = %d, and Digit = %d...\n", testIntC, testDigitC);
    count = getCountRecursive(testIntC, testDigitC, 0);
    printf("count: %zd\n", count);
    assert(count == 177);
    printf("passed!\n");

    printf("all tests passed...\n");
    return 0;
}
