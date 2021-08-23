#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double EPS = 1e-9;

double getMargin(vector<pair<double, double>> &competitors, double aLength, double bLength) {
    vector<double> time;
    for (auto &[a, b] : competitors)
        time.push_back(aLength / a + bLength / b);
    return *min_element(time.begin(), time.end() - 1) - time.back();
}

bool solve() {
    double totalLength;
    int competitorCount;

    if (!(cin >> totalLength >> competitorCount))
        return 0;

    vector<pair<double, double>> competitors(competitorCount);
    for (auto &[a, b] : competitors)
        cin >> a >> b;

    double l = 0, r = totalLength;
    for (int i = 0; i < 300; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = getMargin(competitors, m1, totalLength - m1);
        double f2 = getMargin(competitors, m2, totalLength - m2);
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }

    double margin = getMargin(competitors, l, totalLength - l);

    if (margin >= -EPS) {
        cout.precision(0);
        cout << "The cheater can win by " << fixed << margin * 3600 << " seconds ";
        cout.precision(2);
        cout << "with r = " << fixed << l << "km ";
        cout << "and k = " << fixed << totalLength - l << "km.\n";
    } else {
        cout << "The cheater cannot win.\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}