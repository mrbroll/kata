#include <stdlib.h>

#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct SplitArray {
    int *left;
    int *right;
} SplitArray_t;

int *sort(int *input, size_t length);

SplitArray_t *split(int *input, size_t length);

int *merge(int *left, size_t leftSize, int *right, size_t rightSize);

#ifdef __cplusplus
}
#endif

#endif
