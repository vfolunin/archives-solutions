#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int limit, long long n) {
    return n * log10(n) <= limit * 1e6;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int limit;
    cin >> limit;

    long long l = 0, r = 1;
    while (can(limit, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(limit, m))
            l = m;
        else
            r = m;
    }

    cout << l;
}