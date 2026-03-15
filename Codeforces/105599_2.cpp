#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long value, long long index) {
    return value - value / 2 - value / 3 + value / 6 > index;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int index;
    cin >> index;
    index--;

    long long l = 0, r = 1;
    while (!can(r, index))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(m, index))
            r = m;
        else
            l = m;
    }

    cout << r;
}