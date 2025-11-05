#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double r;
    cin >> r;

    if (r <= 0) {
        cout << "the radius must be greater than 0\n";
        return;
    }

    cout << fixed << 2 * acos(-1) * r << " " << acos(-1) * r * r << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}