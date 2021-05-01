#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long cost(long long kwh) {
    long long res = 0;
    for (auto [amount, tax] : vector<pair<long long, int>>{ {100, 2}, {9900, 3}, {990000, 5} }) {
        long long delta = min(kwh, amount);
        res += delta * tax;
        kwh -= delta;
    }
    res += kwh * 7;
    return res;
}

bool solve() {
    long long totalCost, diffCost;
    cin >> totalCost >> diffCost;

    if (!totalCost)
        return 0;

    long long totalL = 0, totalR = 1e10;
    while (totalL + 1 < totalR) {
        long long totalM = totalL + (totalR - totalL) / 2;
        long long totalMCost = cost(totalM);

        if (totalMCost < totalCost)
            totalL = totalM;
        else
            totalR = totalM;
    }
    long long total = totalR;

    long long al = 0, ar = total;
    while (al + 1 < ar) {
        long long am = al + (ar - al) / 2;
        long long aCost = cost(am);
        long long bCost = cost(total - am);

        if (bCost - aCost < diffCost)
            ar = am;
        else
            al = am;
    }
    long long a = al;

    cout << cost(a) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}