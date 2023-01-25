#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long aMul, long long aMod, long long bMul, long long bMod, long long n, long long t) {
    return aMul * (t - t / aMod) + bMul * (t - t / bMod) >= n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long aMul, aMod, bMul, bMod, n;
    cin >> aMul >> aMod >> bMul >> bMod >> n;

    long long l = 0, r = 1;
    while (!can(aMul, aMod, bMul, bMod, n, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(aMul, aMod, bMul, bMod, n, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}