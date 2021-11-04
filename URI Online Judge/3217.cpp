#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double leakHeight, leakRate, rainTime, deltaTime, height;
    cin >> leakHeight >> leakRate >> rainTime >> deltaTime >> height;

    double l = 0, r = 1e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;

        double leakTime = max(0.0, (rainTime + deltaTime) - (leakHeight / m));
        double rainHeight = rainTime * m;
        if (rainHeight > leakHeight)
            rainHeight = max(leakHeight, rainHeight - leakTime * leakRate);

        if (rainHeight < height)
            l = m;
        else
            r = m;
    }
    double resL = r * rainTime;

    l = 0;
    r = 1e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;

        double leakTime = max(0.0, (rainTime + deltaTime) - (leakHeight / m));
        double rainHeight = rainTime * m;
        if (rainHeight > leakHeight)
            rainHeight = max(leakHeight, rainHeight - leakTime * leakRate);

        if (rainHeight <= height)
            l = m;
        else
            r = m;
    }
    double resR = l * rainTime;

    cout.precision(9);
    cout << fixed << resL << " " << resR << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}