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

    int segmentCount;
    cin >> segmentCount;

    vector<pair<int, int>> segments(segmentCount);
    for (auto &[l, r] : segments)
        cin >> l >> r;

    sort(segments.begin(), segments.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    int res = 0, last = -1e9;
    for (auto &[l, r] : segments) {
        if (last < l) {
            res++;
            last = r;
        }
    }

    cout << res;
}