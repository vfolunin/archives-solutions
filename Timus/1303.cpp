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

    int width;
    cin >> width;

    vector<pair<int, int>> segments;
    while (1) {
        int l, r;
        cin >> l >> r;

        if (!l && !r)
            break;

        if (l <= width && 0 <= r)
            segments.push_back({ l, r });
    }

    sort(segments.begin(), segments.end());

    vector<pair<int, int>> res = { { -1e9, -1e9 } };
    int to = 0;

    for (auto &[l, r] : segments) {
        if (l <= to) {
            if (res.back().second < r)
                res.back() = { l, r };
        } else {
            to = res.back().second;
            if (to >= width)
                break;

            if (to < l) {
                cout << "No solution";
                return 0;
            }

            res.push_back({ l, r });
        }
    }

    if (res.back().second < width) {
        cout << "No solution";
    } else {
        cout << res.size() << "\n";
        for (auto &[l, r] : res)
            cout << l << " " << r << "\n";
    }
}