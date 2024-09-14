#include "include/fact.h"

int factorial(int k) {
    if (k == 0) return 1;
    if (k < 0) return -1;
    return k * factorial(k - 1);
}