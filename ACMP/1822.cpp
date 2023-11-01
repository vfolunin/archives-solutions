#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long a, long long b, long long t) {
    return a * t + (t - 1) * t / 2 <= b * t;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b;
    cin >> a >> b;

    long long l = 0, r = 1;
    while (can(a, b, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(a, b, m))
            l = m;
        else
            r = m;
    }

    cout << r;
}