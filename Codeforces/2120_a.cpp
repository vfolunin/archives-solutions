#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h1, w1, h2, w2, h3, w3;
    cin >> h1 >> w1 >> h2 >> w2 >> h3 >> w3;

    if (h1 == h2 && h1 == h3 && h1 == w1 + w2 + w3 ||
        w1 == w2 && w1 == w3 && w1 == h1 + h2 + h3 ||
        h2 == h3 && h1 + h2 == w1 && h1 + h2 == w2 + w3 ||
        w2 == w3 && w1 + w2 == h1 && w1 + w2 == h2 + h3)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}