#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int ageDiff, ritaBox, theoBox;
    if (!(cin >> ageDiff >> ritaBox >> theoBox))
        return 0;

    for (int theoAge = 3; 1; theoAge++) {
        int ritaAge = theoAge + ageDiff;

        int ritaCandles = (4 + ritaAge) * (ritaAge - 3) / 2;
        int theoCandles = (3 + theoAge) * (theoAge - 2) / 2;

        if (ritaBox >= ritaCandles && ritaBox - ritaCandles == theoCandles - theoBox) {
            cout << ritaBox - ritaCandles << "\n";
            break;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}