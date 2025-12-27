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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int segmentCount;
    cin >> segmentCount;

    vector<pair<int, int>> segments(segmentCount);
    for (auto &[l, r] : segments)
        cin >> l >> r;

    vector<vector<int>> to(18, vector<int>(segments.size() + 1, segments.size()));
    map<int, int> chosenSegments;
    for (int i = 0, j = 0; j < segments.size(); j++) {
        while (1) {
            auto [l, r] = segments[j];
            auto it = chosenSegments.lower_bound(l);
            if (it != chosenSegments.begin() && l <= prev(it)->second || it != chosenSegments.end() && it->first <= r) {
                to[0][i] = j;
                chosenSegments.erase(segments[i].first);
                i++;
            } else {
                chosenSegments[l] = r;
                break;
            }
        }
    }

    for (int level = 1; level < to.size(); level++)
        for (int i = 0; i < segments.size(); i++)
            to[level][i] = to[level - 1][to[level - 1][i]];

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int res = 1;
        for (int level = to.size() - 1; level >= 0; level--) {
            if (to[level][l] <= r) {
                res += 1 << level;
                l = to[level][l];
            }
        }

        cout << res << "\n";
    }
}