#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &dist, int maxDist, int nightCount) {
    int nightNeed = 0, curDist = 0;
    for (int d : dist) {
        if (curDist + d <= maxDist) {
            curDist += d;
        } else {
            nightNeed++;
            curDist = d;
        }
    }
    return nightNeed <= nightCount;
}

bool solve() {
    int campCount, nightCount;
    if (!(cin >> campCount >> nightCount))
        return 0;

    vector<int> dist(campCount + 1);
    for (int &d : dist)
        cin >> d;

    int l = *max_element(dist.begin(), dist.end()) - 1, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(dist, m, nightCount))
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

    while (solve());
}