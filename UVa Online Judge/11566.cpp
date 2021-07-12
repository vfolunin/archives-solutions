#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int friendCount, maxPay, teaCharge, dimCount;
    cin >> friendCount >> maxPay >> teaCharge >> dimCount;

    if (!friendCount)
        return 0;
    friendCount++;

    vector<vector<int>> value(friendCount * 2 + 1, vector<int>(friendCount * maxPay + 1));
    for (int i = 0; i < dimCount; i++) {
        int dimCost;
        cin >> dimCost;

        int dimValue = 0;
        for (int j = 0; j < friendCount; j++) {
            int v;
            cin >> v;
            dimValue += v;
        }

        for (int k = 0; k < 2; k++)
            for (int count = friendCount * 2; count > 0; count--)
                for (int cost = friendCount * maxPay; cost >= dimCost; cost--)
                    value[count][cost] = max(value[count][cost], value[count - 1][cost - dimCost] + dimValue);
    }

    double res = 0;
    for (int count = 1; count <= friendCount * 2; count++)
        for (int cost = 0; cost <= friendCount * maxPay; cost += friendCount)
            if (ceil((cost / friendCount + teaCharge) * 1.1) <= maxPay)
                res = max<double>(res, value[count][cost]);

    cout.precision(2);
    cout << fixed << res / friendCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}