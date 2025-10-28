#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int y, m, d;
    cin >> y >> m >> d;

    if (y < 1989 || y == 1989 && m < 2 || y == 1989 && m == 2 && d <= 27)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}