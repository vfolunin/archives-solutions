#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct PowerTower {
    inline static vector<long double> logLog;

    vector<int> values;
    int index;

    static void prepare() {
        logLog.resize(301);
        for (int i = 2; i < logLog.size(); i++)
            logLog[i] = logl(logl(i));
    }

    bool operator < (const PowerTower &that) const {
        if (logLog.empty())
            prepare();

        const vector<int> &a = values;
        const vector<int> &b = that.values;

        long double inf = numeric_limits<long double>::infinity();
        long double aValue = -inf, bValue = -inf;
        long double neqThreshold = logLog[10];
        long double eqThreshold = logLog[300];

        for (int i = max<int>(a.size(), b.size()) - 1; i >= 0; i--) {
            aValue = i < a.size() ? expl(aValue) + logLog[a[i]] : -inf;
            bValue = i < b.size() ? expl(bValue) + logLog[b[i]] : -inf;

            if (!isfinite(aValue) || !isfinite(bValue)) {
                if (aValue != bValue && max(aValue, bValue) >= neqThreshold)
                    return aValue < bValue;
                continue;
            }

            long double diff = fabsl(aValue - bValue);
            long double eps = 1e-14 * max({ 1.0L, fabsl(aValue), fabsl(bValue) });
            if (diff <= eps && min(aValue, bValue) >= eqThreshold) {
                for (int j = i - 1; j >= 0; j--)
                    if (a[j] != b[j])
                        return a[j] < b[j];
                return 0;
            }

            if (diff >= 5 || min(aValue, bValue) + logl(expm1l(diff)) >= neqThreshold)
                return aValue < bValue;
        }

        return aValue < bValue;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int powerTowerCount;
    cin >> powerTowerCount;

    vector<PowerTower> powerTowers(powerTowerCount);
    for (int i = 0; i < powerTowers.size(); i++) {
        int valueCount;
        cin >> valueCount;
        valueCount++;

        vector<int> &a = powerTowers[i].values;
        a.resize(valueCount);
        for (int &value : a)
            cin >> value;
        a.erase(find(a.begin(), a.end(), 1), a.end());

        powerTowers[i].index = i;
    }

    sort(powerTowers.begin(), powerTowers.end());

    for (PowerTower &powerTower : powerTowers)
        cout << powerTower.index + 1 << " ";
}