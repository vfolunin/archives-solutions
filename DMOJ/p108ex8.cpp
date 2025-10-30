#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int angle;
    cin >> angle;

    if (angle <= 45 || 315 <= angle)
        cout << "N\n";
    else if (angle <= 135)
        cout << "E\n";
    else if (angle <= 225)
        cout << "S\n";
    else
        cout << "W\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}