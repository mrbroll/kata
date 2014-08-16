#include "digit_counter.h"
#include <math.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

size_t getCountIterative(int to, int digit)
{
    if (digit < 0) {
        return 0;
    }

    if (to == 0 && digit == 0) {
        return 1;
    } else if (to == 0) {
        return 0;
    }

    size_t count = 0;
    to = abs(to);
    int log = (int)log10(to);
    int i;
    int j;

    int progress = 0;
    int progressStepSize = to/100 + 1;
    printf("Progress: 0%%");
    fflush(stdout);
    for (i = 0; i <= to; ++i)
    {
        for (j = 0; j <= log; ++j)
        {
            int value = i - (i % (int)pow(10, j));
            int mod = (value - (digit * (int)pow(10, j))) % (int)pow(10, (j + 1));
            if (!mod)
                count++;
        }

        if (i && !(i % progressStepSize)) {
            progress++;
            if (progress <= 10)
                printf("\b\b%d%%", progress);
            else
                printf("\b\b\b%d%%", progress);

            fflush(stdout);
        }
    }

    printf("\b\b\b");
    printf("100%%\n");

    return count;
}

size_t getCountRecursive(int to, int digit, int exp)
{
    if (digit < 0) {
        return 0;
    }

    if (to == 0 && digit == 0) {
        return 1;
    } else if (to == 0) {
        return 0;
    }

    size_t count = 0;
    to = abs(to);
    int log = (int)log10(to);

    count += (int)pow(10, exp) * (to / (int)pow(10, (exp + 1)));

    if (exp < log) {
        count += getCountRecursive(to, digit, exp + 1);
    }

    int ten_exp = (int)pow(10, exp);
    if (((to % (ten_exp * 10)) >= ((digit + 1) * ten_exp)) ||
        (!exp && ((to % (ten_exp * 10)) >= (digit * ten_exp)))) {
        count += ten_exp;
    } else if (exp && ((to % (ten_exp * 10)) >= (digit * ten_exp))) {
        count += (to % ten_exp) + 1;
    }

    return count;
}

#ifdef __cplusplus
}
#endif
