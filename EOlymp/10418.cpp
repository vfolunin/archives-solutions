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

    int res = 0;
    for (int bannedSegment = 0; bannedSegment < segments.size(); bannedSegment++) {
        vector<int> a(1001);

        for (int currentSegment = 0; currentSegment < segments.size(); currentSegment++) {
            if (currentSegment == bannedSegment)
                continue;

            auto [l, r] = segments[currentSegment];
            for (int i = l; i < r; i++)
                a[i]++;
        }

        res = max<int>(res, count_if(a.begin(), a.end(), [](int value) {
            return value > 0;
        }));
    }

    cout << res;
}