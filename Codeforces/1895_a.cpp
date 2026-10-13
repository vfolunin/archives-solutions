#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int chestPos, keyPos, carryLimit;
    cin >> chestPos >> keyPos >> carryLimit;

    if (keyPos < chestPos) {
        cout << chestPos << "\n";
    } else {
        chestPos += min(carryLimit, keyPos - chestPos);

        cout << keyPos + keyPos - chestPos << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}