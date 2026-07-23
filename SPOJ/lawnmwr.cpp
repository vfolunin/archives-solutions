#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

bool solve() {
    int xSegmentCount, ySegmentCount;
    double width;
    cin >> xSegmentCount >> ySegmentCount >> width;

    if (!xSegmentCount && !ySegmentCount && !width)
        return 0;

    vector<pair<double, double>> xSegments(xSegmentCount);
    for (auto &[l, r] : xSegments) {
        double x;
        cin >> x;
        l = x - width / 2;
        r = x + width / 2;
    }
    sort(xSegments.begin(), xSegments.end());

    vector<pair<double, double>> ySegments(ySegmentCount);
    for (auto &[l, r] : ySegments) {
        double y;
        cin >> y;
        l = y - width / 2;
        r = y + width / 2;
    }
    sort(ySegments.begin(), ySegments.end());

    if (EPS < xSegments.front().first || xSegments.back().second + EPS < 75) {
        cout << "NO\n";
        return 1;
    }
    for (int i = 0; i + 1 < xSegments.size(); i++) {
        if (xSegments[i].second + EPS < xSegments[i + 1].first) {
            cout << "NO\n";
            return 1;
        }
    }

    if (EPS < ySegments.front().first || ySegments.back().second + EPS < 100) {
        cout << "NO\n";
        return 1;
    }
    for (int i = 0; i + 1 < ySegments.size(); i++) {
        if (ySegments[i].second + EPS < ySegments[i + 1].first) {
            cout << "NO\n";
            return 1;
        }
    }

    cout << "YES\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}