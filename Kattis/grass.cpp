#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

bool solve() {
    int sprinklerCount;
    double length, width;
    if (!(cin >> sprinklerCount >> length >> width))
        return 0;
    width /= 2;

    vector<pair<double, double>> segments;
    for (int i = 0; i < sprinklerCount; i++) {
        double coord, radius;
        cin >> coord >> radius;

        if (radius > width + EPS) {
            double dist = sqrt(radius * radius - width * width);
            segments.push_back({ coord - dist, coord + dist });
        }
    }
    sort(segments.begin(), segments.end());

    int res = 0;
    double right = 0, nextRight = 0;
    for (int i = 0; i < segments.size(); ) {
        while (i < segments.size() && segments[i].first <= right + EPS) {
            nextRight = max(nextRight, segments[i].second);
            i++;
        }

        res++;
        right = nextRight;

        if (length <= right + EPS)
            break;

        if (i < segments.size() && right + EPS < segments[i].first) {
            cout << "-1\n";
            return 1;
        }
    }

    if (right >= length - EPS)
        cout << res << "\n";
    else
        cout << "-1\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}