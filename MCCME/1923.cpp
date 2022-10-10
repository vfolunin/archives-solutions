#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long n, long long h, long long w, long long size) {
    return (size / h) * (size / w) >= n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n, h, w;
    cin >> h >> w >> n;

    long long l = 0, r = 1;
    while (!can(n, h, w, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(n, h, w, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}