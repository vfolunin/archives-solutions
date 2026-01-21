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

    int pointCount;
    cin >> pointCount;

    vector<pair<int, int>> points(pointCount);
    unordered_map<int, vector<int>> xs, ys;
    for (auto &[x, y] : points) {
        cin >> x >> y;

        xs[y].push_back(x);
        ys[x].push_back(y);
    }

    for (auto &[y, xs] : xs)
        sort(xs.begin(), xs.end());
    for (auto &[x, ys] : ys)
        sort(ys.begin(), ys.end());

    long long res = 0;
    for (auto &[x, y] : points) {
        long long xLess = lower_bound(xs[y].begin(), xs[y].end(), x) - xs[y].begin();
        long long xGreater = xs[y].end() - upper_bound(xs[y].begin(), xs[y].end(), x);
        long long yLess = lower_bound(ys[x].begin(), ys[x].end(), y) - ys[x].begin();
        long long yGreater = ys[x].end() - upper_bound(ys[x].begin(), ys[x].end(), y);
        res += (xLess + xGreater) * (yLess + yGreater);
    }

    cout << res;
}