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

    int segmentCount, roomCount;
    cin >> segmentCount >> roomCount;

    vector<pair<int, int>> segments(segmentCount);
    for (auto &[l, r] : segments)
        cin >> l >> r;
    sort(segments.begin(), segments.end(), compare);

    multiset<int> ends;
    int res = 0;

    for (auto &[l, r] : segments) {
        auto it = ends.lower_bound(l);
        if (it != ends.begin()) {
            ends.erase(--it);
            ends.insert(r);
            res++;
        } else if (ends.size() < roomCount) {
            ends.insert(r);
            res++;
        }
    }

    cout << res;
}