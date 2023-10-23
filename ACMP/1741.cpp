#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<pair<double, double>> &limits, double time, int exceed) {
    for (auto &[limit, length] : limits)
        time -= length / (limit + exceed);
    return time >= 0;
}

long long getExceed(vector<pair<double, double>> &limits, double time) {
    long long l = -1, r = 1;
    while (!can(limits, time, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(limits, time, m))
            r = m;
        else
            l = m;
    }

    return r;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int limitCount;
    cin >> limitCount;

    vector<pair<double, double>> limits(limitCount);
    for (auto &[limit, length] : limits)
        cin >> limit;
    for (auto &[limit, length] : limits)
        cin >> length;

    int fineCount;
    cin >> fineCount;

    vector<pair<long long, int>> fines(fineCount, { 1e18, 0 });
    for (int i = 0; i + 1 < fines.size(); i++)
        cin >> fines[i].first;
    for (auto &[exceed, fine] : fines)
        cin >> fine;

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int inTime, outTime;
        cin >> inTime >> outTime;

        long long exceed = getExceed(limits, outTime - inTime);
        if (exceed == 0)
            cout << "0\n";
        else
            cout << upper_bound(fines.begin(), fines.end(), make_pair(exceed, 0))->second << "\n";
    }
}