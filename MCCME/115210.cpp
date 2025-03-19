#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long threshold, vector<vector<int>> &drills, long long voltage) {
    long long sum = 0;
    for (vector<int> &drill : drills) {
        sum += min<long long>(voltage, drill[0]) * drill[1] + max(voltage - drill[0], 0LL) * drill[2];
        if (sum >= threshold)
            return 1;
    }
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int drillCount;
    long long threshold;
    cin >> drillCount >> threshold;

    vector<vector<int>> drills(drillCount, vector<int>(3));
    for (vector<int> &drill : drills)
        cin >> drill[0] >> drill[1] >> drill[2];

    long long l = 0, r = 1;
    while (!can(threshold, drills, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(threshold, drills, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}