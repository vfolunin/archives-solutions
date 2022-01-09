#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    int cx, cy, r1, r2;
    cin >> cx >> cy >> r1 >> r2;
    r1 *= r1;
    r2 *= r2;

    vector<int> score1(2), score2(2);
    for (int i = 0; i < 2 * pointCount; i++) {
        int x, y;
        cin >> x >> y;
        int r = (x - cx) * (x - cx) + (y - cy) * (y - cy);
        score1[i % 2] += r < r1;
        score2[i % 2] += r <= r2;
    }

    if (score1[0] > score1[1] || score1[0] == score1[1] && score2[0] > score2[1])
        cout << "C > P\n";
    else if (score1[0] == score1[1] && score2[0] == score2[1])
        cout << "C = P\n";
    else
        cout << "P > C\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}