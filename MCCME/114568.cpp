#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long time, long long dist) {
    return (time / 2) * ((time + 1) / 2) >= dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long dist;
    cin >> dist;

    long long l = 0, r = 1;
    while (!can(r, dist))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(m, dist))
            r = m;
        else
            l = m;
    }

    cout << r;
}