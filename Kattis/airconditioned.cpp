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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int segmentCount;
    cin >> segmentCount;

    vector<pair<int, int>> segments(segmentCount);
    for (auto &[l, r] : segments)
        cin >> l >> r;

    sort(segments.begin(), segments.end(), compare);

    int pointCount = 1, last = segments[0].second;
    for (auto &[l, r] : segments) {
        if (last < l) {
            pointCount++;
            last = r;
        }
    }

    cout << pointCount;
}