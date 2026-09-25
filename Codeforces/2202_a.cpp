#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int w, h;
    cin >> w >> h;

    if (h > 0)
        w -= h * 2;
    else if (h < 0)
        w += h * 4;

    cout << (w >= 0 && w % 3 == 0 ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}