#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<long long> &b, long long machineCount, long long extraCount, long long distance) {
    long long pairCount = 0, unusedCount = 0;
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
    long long machineCount, batteryPerMachine;
    if (!(cin >> machineCount >> batteryPerMachine))
        return 0;

    vector<long long> b(2 * machineCount * batteryPerMachine);
    for (long long &x : b)
        cin >> x;
    sort(b.rbegin(), b.rend());

    long long l = -1, r = 1e18;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
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