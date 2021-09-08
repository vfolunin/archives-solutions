#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Segment {
    int l, r;

    bool operator < (const Segment &that) const {
        if (r != that.r)
            return r < that.r;
        return l < that.l;
    }
};

void solve() {
    int segmentCount;
    cin >> segmentCount;

    vector<Segment> segments(segmentCount);
    for (auto &[l, r] : segments)
        cin >> l >> r;

    sort(segments.begin(), segments.end());

    int res = 0, last = segments[0].r;
    for (auto &[l, r] : segments) {
        if (last != r) {
            if (l <= last) {
                last++;
            } else {
                last = r;
                res++;
            }
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