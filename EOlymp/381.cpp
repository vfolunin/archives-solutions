#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long binPow(long long x, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x;
    long long r = binPow(x, p / 2);
    return r * r;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value, power;
    cin >> value >> power;

    int res = 1;
    while (binPow(res, power) < value)
        res++;

    if (abs(value - binPow(res - 1, power)) < abs(value - binPow(res, power)))
        res--;

    cout << res;
}