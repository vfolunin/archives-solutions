#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcdex(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1, d = gcdex(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

long long inv(long long a, long long mod) {
    long long x, y;
    return a && gcdex(a, mod, x, y) == 1 ? (x % mod + mod) % mod : 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, mod;
    cin >> a >> mod;

    cout << inv(a, mod);
}