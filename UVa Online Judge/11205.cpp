#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

void solve() {
    int ledCount, symbolCount;
    cin >> ledCount >> symbolCount;

    vector<int> symbols;
    for (int i = 0; i < symbolCount; i++) {
        int symbol = 0;
        for (int j = 0; j < ledCount; j++) {
            int led;
            cin >> led;
            symbol = symbol * 2 + led;
        }
        symbols.push_back(symbol);
    }

    int res = ledCount;
    for (int mask = 0; mask < (1 << ledCount); mask++) {
        set<int> symbolSet;
        for (int symbol : symbols)
            symbolSet.insert(symbol & mask);
        if (symbolSet.size() == symbolCount)
            res = min(res, ones(mask));
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}