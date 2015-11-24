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

size_t getCountRecursive(int to, int digit)
{
    if (to == 0) {
        return 0;
    }
    to = abs(to);
    int log = (int)log10(to);
    // get most significant digit
    int msd = to / pow(10, log);
    // get least significant digits
    int lsds = to - msd * pow(10, log);
    int sub_msd = msd - 1;
    int extra = 0;
    if (msd == digit) {
        extra = lsds + 1;
    } else if (msd > digit) {
        extra = pow(10, log);
    }
    int current_count = 0;
    if (log > 0) {
        current_count = (int)pow(10, log - 1) * log * (sub_msd + 1);
    }
    return current_count + extra + getCountRecursive(lsds, digit);
}

#ifdef __cplusplus
}
#endif
