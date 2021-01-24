#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int players, winner;
    double winP;
    cin >> players >> winP >> winner;

    double loseP = 1 - winP;
    double resP = winP ? winP * pow(loseP, winner - 1) / (1 - pow(loseP, players)) : 0;

    cout.precision(4);
    cout << fixed << resP << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}