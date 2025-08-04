#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int threshold, segmentCount;
    cin >> threshold >> segmentCount;

    vector<pair<int, int>> segments(segmentCount);
    for (auto &[l, r] : segments)
        cin >> l >> r;

    sort(segments.begin(), segments.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    vector<int> res(24001);
    for (int t = 1, i = 0; t < res.size(); t++) {
        res[t] = res[t - 1];
        while (i < segments.size() && segments[i].second == t) {
            res[t] = max(res[t], res[segments[i].first] + 1);
            i++;
        }
    }

    cout << (res.back() >= threshold ? "YES" : "NO");
}