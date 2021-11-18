#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> x(5), y(5);
    for (int i = 0; i < 5; i++)
        cin >> x[i] >> y[i];

    cout << (x[0] <= x[4] && x[4] <= x[1] &&
             x[3] <= x[4] && x[4] <= x[2] &&
             y[0] <= y[4] && y[4] <= y[3] &&
             y[1] <= y[4] && y[4] <= y[2]) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}