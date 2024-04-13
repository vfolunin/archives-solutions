#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int josephus(int n) {
    int highestBit = -1;
    for (int bit = 0; bit < 16; bit++)
        if (n & (1 << bit))
            highestBit = bit;
    n &= (1 << highestBit) - 1;
    return (n << 1) + 1;
}

void solve(int test) {
    int n;
    cin >> n;

    set<int> seen;
    int rounds = 0;
    while (!seen.count(n)) {
        seen.insert(n);
        rounds++;
        n = josephus(n);
    }

    cout << "Case " << test << ": " << rounds - 1 << " " << n << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}