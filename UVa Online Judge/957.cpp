#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int period, popeCount;
    if (!(cin >> period >> popeCount))
        return 0;

    vector<int> popes(popeCount);
    for (int &p : popes)
        cin >> p;

    int bestL = 0, bestR = 0;
    for (int l = 0, r = 0; l < popeCount; l++) {
        while (r + 1 < popeCount && popes[r + 1] - popes[l] < period)
            r++;
        if (r - l > bestR - bestL) {
            bestL = l;
            bestR = r;
        }
    }

    cout << bestR - bestL + 1 << " " << popes[bestL] << " " << popes[bestR] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}