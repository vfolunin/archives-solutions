#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &b, int machineCount, int extraCount, int distance) {
    int pairCount = 0, unusedCount = 0;
    for (int i = 0; i + 1 < b.size(); i++) {
        if (b[i] - b[i + 1] <= distance && unusedCount >= extraCount) {
            pairCount++;
            unusedCount -= extraCount;
            i++;
        } else {
            unusedCount++;
        }
    }
    return pairCount >= machineCount;
}

bool solve() {
    int machineCount, batteryPerMachine;
    if (!(cin >> machineCount >> batteryPerMachine))
        return 0;

    vector<int> b(2 * machineCount * batteryPerMachine);
    for (int &x : b)
        cin >> x;
    sort(b.rbegin(), b.rend());

    int l = -1, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(b, machineCount, (batteryPerMachine - 1) * 2, m))
            r = m;
        else
            l = m;
    }

    cout << r << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}