#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    long long res[2] = {};
    int bitNumber = 0;
    for (int bit = 0; bit < 60; bit++)
        if (n & (1LL << bit))
            res[bitNumber++ % 2] |= 1LL << bit;

    cout << res[0] << " " << res[1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}