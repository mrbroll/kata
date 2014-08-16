#include "digit_counter.h"
#include <math.h>

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

    for (i = 0; i <= to; ++i)
    {
        for (j = 0; j <= log; ++j)
        {
            int value = i - (i % (int)pow(10, j));
            int mod = (value - (digit * (int)pow(10, j))) % (int)pow(10, (j + 1));
            if (!mod)
                count++;
        }
    }

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

    exp++;

    count += pow(10, exp) * (to / pow(10, exp));

    if (exp < log) {
        count += getCountRecursive(to, digit, exp);
    }

    int ten_exp = pow(10, exp);
    if ((to % (ten_exp * 10)) >= (digit * ten_exp)) {
        count += pow(10, exp);
    } else if (exp) {
        count += (to % ten_exp);
    }

    return count;
}

#ifdef __cplusplus
}
#endif
