#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int pointCount;
    cin >> pointCount;

    vector<pair<int, int>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;
    sort(points.begin(), points.end());

    int res = 0;

    for (int i = 0; i < points.size(); i++) {
        auto &[x1, y1] = points[i];
        for (int j = i + 1; j < points.size(); j++) {
            auto &[x2, y2] = points[j];
            res += x1 != x2 && y1 != y2 &&
                   binary_search(points.begin(), points.end(), make_pair(x1, y2)) &&
                   binary_search(points.begin(), points.end(), make_pair(x2, y1));
        }
    }

    cout << "Case " << test << ": " << res / 2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}