#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getCountTo(long long n, int base) {
    long long res = 0;
    for (long long d = base, factor = 1; d <= n; d *= base, factor *= -1)
        res += n / d * factor;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long index;
    int base;
    cin >> index >> base;

    long long l = 0, r = 1;
    while (getCountTo(r, base) < index)
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (getCountTo(m, base) < index)
            l = m;
        else
            r = m;
    }

    cout << r;
}