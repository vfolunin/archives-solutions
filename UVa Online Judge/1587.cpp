#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<pair<int, int>> rects(6);
    for (auto &[h, w] : rects) {
        if (!(cin >> h >> w))
            return 0;
        if (h > w)
            swap(h, w);
    }

    sort(rects.begin(), rects.end());

    if (rects[0] != rects[1] || rects[2] != rects[3] || rects[4] != rects[5] ||
        rects[0].first != rects[2].first || rects[0].second != rects[4].first || rects[2].second != rects[4].second)
        cout << "IMPOSSIBLE\n";
    else
        cout << "POSSIBLE\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}