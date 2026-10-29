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

    double radius, lat1, lon1, lat2, lon2;
    cin >> radius >> lat1 >> lon1 >> lat2 >> lon2;

    double coeff = acos(-1.0) / 180;
    lat1 *= coeff;
    lon1 *= coeff;
    lat2 *= coeff;
    lon2 *= coeff;

    double cosValue = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2);
    double res = radius * acos(cosValue);

    cout << fixed << res;
}