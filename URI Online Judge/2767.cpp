#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int aSize, bSize, factor;
    if (!(cin >> aSize >> bSize >> factor))
        return 0;

    vector<int> aModCount(factor);
    for (int i = 0; i < aSize; i++) {
        int x;
        cin >> x;
        aModCount[x % factor]++;
    }

    vector<int> bModCount(factor);
    for (int i = 0; i < bSize; i++) {
        int x;
        cin >> x;
        bModCount[x % factor]++;
    }

    long long res = 1LL * aModCount[0] * bModCount[0];
    for (int ai = 1, bi = factor - 1; ai < factor; ai++, bi--)
        res += 1LL * aModCount[ai] * bModCount[bi];

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}