#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long ones(long long n) {
    long long res = 0;
    for (int bit = 62; bit >= 0; bit--) {
        if (n & (1LL << bit)) {
            res += bit * (1LL << (bit - 1));
            res += (n & ((1LL << (bit + 1)) - 1)) - (1LL << bit) + 1;
        }
    }
    return res;
}

bool solve() {
    long long l, r;
    if (!(cin >> l >> r))
        return 0;

    cout << ones(r) - (l ? ones(l - 1) : 0) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}