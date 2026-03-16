#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<double> pieSizes, double pieceSize, int friendCount) {
    int pieceCount = 0;
    for (double pieSize : pieSizes)
        pieceCount += floor(pieSize / pieceSize);
    return pieceCount >= friendCount;
}

void solve() {
    int pieCount, friendCount;
    cin >> pieCount >> friendCount;
    friendCount++;

    vector<double> pieSizes(pieCount);
    for (int i = 0; i < pieCount; i++) {
        double r;
        cin >> r;
        pieSizes[i] = acos(-1) * r * r;
    }

    double l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        if (can(pieSizes, m, friendCount))
            l = m;
        else
            r = m;
    }

    cout.precision(4);
    cout << fixed << l << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}