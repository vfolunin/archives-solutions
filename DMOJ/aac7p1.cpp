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

    if (w == 1 || h == 1 && w < 7 || w < 4 && h < 4)
        cout << "bad\n";
    else
        cout << "good\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}