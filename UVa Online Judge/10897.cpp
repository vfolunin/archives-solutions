#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double read() {
    double deg, min, sec;
    char c;
    cin >> deg >> min >> sec >> c;

    deg += min / 60 + sec / 3600;
    if (c == 'S' || c == 'W')
        deg = -deg;
    return (deg / 180) * acos(-1);
}

const double R = 6371.01;

void solve() {
    double lat1 = read(), lon1 = read();
    double lat2 = read(), lon2 = read();
    double angle = acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2));
    
    cout.precision(2);
    cout << fixed << R * angle << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}