#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    pair<int, int> start;
    vector<pair<int, int>> points;
    vector<vector<int>> memo;

    int dist(pair<int, int> &a, pair<int, int> &b) {
        return max(abs(a.first - b.first), abs(a.second - b.second));
    }

    int dist(int mask, int last) {
        int &res = memo[mask][last];
        if (res != 1e9)
            return res;

        if (!(mask & (mask - 1)))
            return res = dist(start, points[last]);

        for (int prev = 0; prev < points.size(); prev++) {
            if (prev == last || !(mask & (1 << prev)))
                continue;
            res = min(res, dist(mask ^ (1 << last), prev) + dist(points[prev], points[last]));
        }
        return res;
    }

    int solve() {
        if (points.empty())
            return 0;
        memo.assign(1 << points.size(), vector<int>(points.size(), 1e9));
        int res = 1e9;
        for (int last = 0; last < points.size(); last++)
            res = min(res, dist((1 << points.size()) - 1, last) + dist(points[last], start));
        return res;
    }
};

bool solve() {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    Solver solver;
    for (int y = 0; y < h; y++) {
        string line;
        cin >> line;
        for (int x = 0; x < w; x++) {
            if (line[x] == 'L')
                solver.start = { y, x };
            else if (line[x] == '#')
                solver.points.push_back({ y, x });
        }
    }

    cout << solver.solve() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}