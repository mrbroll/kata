#include "merge_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    int testInputA[] = {9, 38, 4, 27, 195, 22, 987, -312, 14, 0};
    int sortedInputA[] = {-312, 0, 4, 9, 14, 22, 27, 38, 195, 987};
    size_t testInputLengthA = 10;
    int testInputB[] = {4, 92, 58, 1456, -478, -3872, 25, 4, 0, 0, 58, 92, 4};
    int sortedInputB[] = {-3872, -478, 0, 0, 4, 4, 4, 25, 58, 58, 92, 92, 1456};
    size_t testInputLengthB = 13;


    int *resultA = sort(testInputA, testInputLengthA);
    int *resultB = sort(testInputB, testInputLengthB);

    int i;
    for (i = 0; i < testInputLengthA; i++)
    {
        int sorted = resultA[i];
        int reference = sortedInputA[i];
        assert(sorted == reference);
    }
    printf("passed all tests for input A\n");

    for (i = 0; i < testInputLengthB; i++)
    {
        int sorted = resultB[i];
        int reference = sortedInputB[i];
        assert(sorted == reference);
    }
    printf("passed all tests for input B\n");

    printf("passed all tests! Woohoo!\n");

    return 0;
}
