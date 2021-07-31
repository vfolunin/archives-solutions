#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int length, segmentCount;
    cin >> length >> segmentCount;

    if (!length)
        return 0;

    vector<pair<int, int>> segments(segmentCount);
    for (auto &[l, r] : segments) {
        int coord, radius;
        cin >> coord >> radius;
        l = max(0, coord - radius);
        r = min(length, coord + radius);
    }

    sort(segments.begin(), segments.end());

    int coverCount = 0, r = 0;
    for (int i = 0; i < segmentCount && r < length; ) {
        int j = i, nextR = r;
        while (j < segmentCount && segments[j].first <= r) {
            nextR = max(nextR, segments[j].second);
            j++;
        }

        if (nextR == r) {
            cout << "-1\n";
            return 1;
        }

        coverCount++;
        r = nextR;
        i = j;
    }

    cout << (r == length ? segmentCount - coverCount : -1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}