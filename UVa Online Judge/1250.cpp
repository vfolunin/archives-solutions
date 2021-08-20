#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sum(vector<int> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<int> x(pointCount + 2), y(pointCount + 2), p(pointCount + 2);
    for (int i = 1; i <= pointCount; i++)
        cin >> x[i] >> y[i] >> p[i];
    x.back() = y.back() = 100;

    vector<int> pp(pointCount + 2);
    for (int i = 1; i < pointCount + 2; i++)
        pp[i] = pp[i - 1] + p[i];

    vector<double> score(pointCount + 2, 1e9);
    score[0] = 0;
    for (int i = 1; i < pointCount + 2; i++)
        for (int j = 0; j < i; j++)
            score[i] = min(score[i], score[j] + hypot(x[i] - x[j], y[i] - y[j]) + sum(pp, j + 1, i - 1) + 1);
    
    cout.precision(3);
    cout << fixed << score.back() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}