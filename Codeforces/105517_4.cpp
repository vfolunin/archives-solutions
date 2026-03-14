#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long area, divisor = 1, sqrt_n = 1;
    cin >> area;

    long long h = 1;
    for (long long d = 2; d * d <= area; d++)
        if (area % d == 0)
            h = d;
    long long w = area / h;

    cout << (long long)ceil(hypot(h, w) / 2);
}