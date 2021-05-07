#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n, l, r;
    if (!(cin >> n >> l >> r))
        return 0;

    long long mask = 0;
    for (int bit = 32; bit >= 0; bit--)
        if (!(n & (1LL << bit)) && (mask | (1LL << bit)) <= r || (mask | (1LL << bit)) <= l)
            mask |= 1LL << bit;

    cout << mask << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}