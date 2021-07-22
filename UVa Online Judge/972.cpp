#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<pair<double, double>> readSegments() {
    int segmentCount = 0;
    if (cin >> segmentCount);

    vector<pair<double, double>> segments;
    double x = 0;

    for (int i = 0; i < segmentCount; i++) {
        double h, w;
        cin >> h >> w;
        segments.push_back({ x, h });
        x += w;
    }

    return segments;
}

double getY(vector<pair<double, double>> &segments, double x) {
    return (--upper_bound(segments.begin(), segments.end(), make_pair(x + 1e-9, 1e9)))->second;
}

bool solve() {
    vector<pair<double, double>> a = readSegments(), b = readSegments();
    if (a.empty())
        return 0;

    set<double> xs;
    for (auto &[x, _] : a)
        xs.insert(x);
    for (auto &[x, _] : b)
        xs.insert(x);

    double res = 1e9;
    for (double x : xs)
        res = min(res, max(getY(a, x), getY(b, x)));

    cout.precision(3);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}