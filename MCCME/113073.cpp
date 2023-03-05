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

    int size;
    cin >> size;

    vector<pair<int, int>> segments(size);
    for (auto &[l, r] : segments)
        cin >> l >> r;

    sort(segments.begin(), segments.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    int last = 0, res = 0;
    for (auto &[l, r] : segments) {
        if (last <= l) {
            last = r;
            res++;
        }
    }

    cout << res;
}