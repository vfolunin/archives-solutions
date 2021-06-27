#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<double> readDoubles() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<double> res;
    double x;
    while (ss >> x)
        res.push_back(x);
    return res;
}

double crossProduct(double x1, double y1, double x2, double y2) {
    return x1 * y2 - y1 * x2;
}

double area(vector<double> &polygon) {
    double s = 0;
    for (int i = 0; i + 3 < polygon.size(); i += 2)
        s += crossProduct(polygon[i], polygon[i + 1], polygon[i + 2], polygon[i + 3]);
    return fabs(s) / 2;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    double v1 = 0;
    for (int i = 0; i < n; i++) {
        double h;
        cin >> h;
        vector<double> polygon = readDoubles();
        v1 += h * area(polygon);
    }

    double r, h;
    cin >> r >> h;

    double v2 = h * acos(-1) * r * r;

    cout.precision(0);
    cout << fixed << floor(v1 / v2) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}