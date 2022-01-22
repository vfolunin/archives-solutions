#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double R = 6371009;

double rad(double deg) {
    return deg / 180 * acos(-1);
}

void solve() {
    double lat1, lon1, lat2, lon2;
    cin >> lat1 >> lon1 >> lat2 >> lon2;

    lat1 = rad(lat1);
    lon1 = rad(lon1);
    lat2 = rad(lat2);
    lon2 = rad(lon2);

    double x1 = cos(lon1) * cos(lat1), y1 = sin(lon1) * cos(lat1), z1 = sin(lat1);
    double x2 = cos(lon2) * cos(lat2), y2 = sin(lon2) * cos(lat2), z2 = sin(lat2);
    double distA = hypot(hypot(x1 - x2, y1 - y2), z1 - z2);
    double distB = 2 * asin(distA / 2);

    cout.precision(8);
    cout << fixed << R * (distB - distA) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}