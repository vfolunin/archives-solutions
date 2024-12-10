#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<int, pair<int, int>> segment;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (!segment.count(value))
            segment[value] = { i, i };
        else
            segment[value].second = i;
    }

    vector<pair<int, int>> segments;
    for (auto &[_, segment] : segment)
        segments.push_back(segment);

    sort(segments.begin(), segments.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    int res = segments.size(), last = -1;
    for (auto &[l, r] : segments) {
        if (last < l) {
            res--;
            last = r;
        }
    }

    cout << res;
}