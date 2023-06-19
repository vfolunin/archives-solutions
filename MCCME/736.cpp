#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Segment {
    int l, r, i;

    bool operator < (const Segment &that) const {
        return r < that.r;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int segmentCount;
    cin >> segmentCount;

    vector<Segment> segments(segmentCount);
    for (int i = 0; i < segments.size(); i++) {
        cin >> segments[i].l >> segments[i].r;
        segments[i].i = i + 1;
    }

    sort(segments.begin(), segments.end());

    int last = 0;
    for (auto &[l, r, i] : segments) {
        if (last <= l) {
            last = r;
            cout << i << " ";
        }
    }
}