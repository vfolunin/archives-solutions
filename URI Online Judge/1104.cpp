#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int aSize, bSize;
    cin >> aSize >> bSize;

    if (!aSize && !bSize)
        return 0;

    map<int, int> aCount;
    for (int i = 0; i < aSize; i++) {
        int x;
        cin >> x;
        aCount[x]++;
    }

    map<int, int> bCount;
    for (int i = 0; i < bSize; i++) {
        int x;
        cin >> x;
        bCount[x]++;
    }

    int aRes = 0;
    for (auto &[x, count] : aCount)
        aRes += !bCount.count(x);

    int bRes = 0;
    for (auto &[x, count] : bCount)
        bRes += !aCount.count(x);

    cout << min(aRes, bRes) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}