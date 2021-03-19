#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

bool solve() {
    int segmentCount;
    cin >> segmentCount;

    if (!segmentCount)
        return 0;

    vector<pair<int, int>> segments(segmentCount);
    for (auto &[l, r] : segments)
        cin >> l >> r;
    sort(segments.begin(), segments.end(), compare);

    int last = -1, res = 0;
    for (auto &[l, r] : segments) {
        if (l < last)
            continue;
        res++;
        last = r;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}