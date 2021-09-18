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

void solve() {
    int segmentCount;
    cin >> segmentCount;

    vector<pair<int, int>> segments(segmentCount);
    for (auto &[l, r] : segments)
        cin >> l >> r;
    sort(segments.begin(), segments.end(), compare);

    int last = -1e9, res = 0;
    for (auto &[l, r] : segments) {
        if (last <= l) {
            res++;
            last = r;
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}