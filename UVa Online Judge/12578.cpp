#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double l;
    cin >> l;

    double w = l * 0.6, r = l * 0.2;
    double sRectangle = l * w, sCircle = acos(-1.0) * r * r;

    cout.precision(2);
    cout << fixed << sCircle << " " << sRectangle - sCircle << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}