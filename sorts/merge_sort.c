#include "merge_sort.h"
#include <stdlib.h>
#include <string.h>

int *sort(int *input, size_t length)
{
    int *sortedResult = NULL;
    if (length >= 2) {
        SplitArray_t *subArrays = split(input, length);
        size_t leftLength = length / 2;
        size_t rightLength = leftLength;
        if (length % 2)
            rightLength++;

        if (length > 3) {
            subArrays->left = sort(subArrays->left, leftLength);
            subArrays->right = sort(subArrays->right, rightLength);
        } else if (length == 3) {
            subArrays->right = sort(subArrays->right, rightLength);
        }

        sortedResult = merge(subArrays->left, leftLength, subArrays->right, rightLength);
    } else {
        sortedResult = input;
    }

    return sortedResult;
}

SplitArray_t *split(int *input, size_t length) {
    size_t leftLength = length/2;
    size_t rightLength = leftLength;
    if (length % 2)
        rightLength++;

    SplitArray_t *retVal = (SplitArray_t *)malloc(sizeof(SplitArray_t));
    retVal->left = (int *)malloc(sizeof(int) * leftLength);
    retVal->right = (int *)malloc(sizeof(int) * rightLength);
    memcpy((void *)retVal->left, (void *)input, sizeof(int) * leftLength);
    memcpy((void *)retVal->right, (void *)(input + leftLength), sizeof(int) * rightLength);
    // should check that left and right are non-null, but that's too tedious for the purpose of this exercise
    return retVal;
}

int *merge(int *left, size_t leftLength, int *right, size_t rightLength)
{
    int *retVal = (int *)malloc(sizeof(int) * (leftLength + rightLength));
    int r = 0;
    int l = 0;
    int retIndex = 0;
    while (l < leftLength && r < rightLength)
    {
        if (left[l] <= right[r]) {
            retVal[retIndex] = left[l];
            l++;
        } else {
            retVal[retIndex] = right[r];
            r++;
        }
        retIndex++;
    }

    while (l < leftLength) {
        retVal[retIndex] = left[l];
        l++;
        retIndex++;
    }

    while (r < rightLength) {
        retVal[retIndex] = right[r];
        r++;
        retIndex++;
    }

    return retVal;
}
