#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int circleCount;
    double x1, y1;
    cin >> circleCount >> x1 >> y1;

    vector<pair<double, double>> segments;
    for (int i = 0; i < circleCount; i++) {
        double x2, y2, radius;
        cin >> x2 >> y2 >> radius;

        double angle = atan2(y2 - y1, x2 - x1);
        double delta = asin(radius / hypot(x2 - x1, y2 - y1));
        segments.push_back({ angle - delta, angle + delta });
    }

    sort(segments.begin(), segments.end());

    double l = segments[0].first, r = segments[0].second;
    for (int i = 1; i < segments.size(); i++) {
        if (r + 1e-9 < segments[i].first) {
            cout << "NO";
            return 0;
        }
        r = max(r, segments[i].second);
    }
    
    cout << (r - l + 1e-9 >= 2 * acos(-1.0) ? "YES" : "NO");
}