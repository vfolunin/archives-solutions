#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool solve() {
    vector<pair<int, int>> points;
    while (1) {
        int x, y;
        cin >> x >> y;

        if (!x && !y)
            break;

        points.push_back({ x, y });
    }

    if (points.empty())
        return 0;
    sort(points.begin(), points.end());

    vector<vector<int>> res;

    for (int i = 0; i < points.size(); i++) {
        map<pair<int, int>, vector<int>> line;
        for (int j = 0; j < points.size(); j++) {
            if (i == j)
                continue;
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;
            int d = gcd(dx, dy);
            line[{dx / d, dy / d}].push_back(j);
        }
        for (auto &[_, l] : line) {
            if (l.size() > 1 && l[0] > i) {
                res.push_back({ i });
                res.back().insert(res.back().end(), l.begin(), l.end());
            }
        }
    }

    sort(res.begin(), res.end());

    if (res.empty()) {
        cout << "No lines were found\n";
    } else {
        cout << "The following lines were found:\n";
        for (vector<int> &line : res) {
            for (int i : line)
                cout << "(" << setw(4) << points[i].first << "," << setw(4) << points[i].second << ")";
            cout << "\n";
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}