#include "kakor.h"

long long cookies(int size, int a[]) {
    long long res = 0;
    for (int i = 0; i < size; i++)
        res += a[i];
    return res;
}