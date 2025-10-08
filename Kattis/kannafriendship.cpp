#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentSet {
    set<pair<int, int>> segments;
    int totalSize = 0;

    void addSegment(int l, int r) {
        auto it = segments.lower_bound({ l, l });
        if (it != segments.begin() && l <= prev(it)->second)
            it--;

        while (it != segments.end() && l <= it->second && it->first <= r) {
            l = min(l, it->first);
            r = max(r, it->second);
            totalSize -= it->second - it->first + 1;
            it = segments.erase(it);
        }

        totalSize += r - l + 1;
        segments.insert({ l, r });
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount >> queryCount;

    SegmentSet segmentSet;

    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;

            segmentSet.addSegment(l, r);
        } else {
            cout << segmentSet.totalSize << "\n";
        }
    }
}