#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;

    cout << (h1 < h2 && w1 < w2 || h1 < w2 && w1 < h2 ? "S\n" : "N\n");        
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}