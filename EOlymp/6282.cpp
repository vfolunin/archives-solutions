#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getScore(int a, int c, int r, int g, int b) {
    return a * (r * r + g * g + b * b) + c * min({ r, g, b });
}

void solve() {
    int a, c, r, g, b;
    cin >> a >> c >> r >> g >> b;

    int rScore = getScore(a, c, r + 1, g, b);
    int gScore = getScore(a, c, r, g + 1, b);
    int bScore = getScore(a, c, r, g, b + 1);

    if (rScore >= gScore && rScore >= bScore)
        cout << "RED\n";
    else if (gScore >= rScore && gScore >= bScore)
        cout << "GREEN\n";
    else
        cout << "BLUE\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}