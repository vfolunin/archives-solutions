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
    for (auto &[l, r] : segments) {
        int x, delta;
        cin >> x >> delta;

        l = x - delta;
        r = x + delta;
    }

    sort(segments.begin(), segments.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    int last = -2e9, res = 0;
    for (auto &[l, r] : segments) {
        if (last <= l) {
            last = r;
            res++;
        }
    }

    cout << res;
}