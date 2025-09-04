#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    a %= 3;
    b %= 3;

    if (a == b)
        cout << "DRAW\n";
    else if ((a + 1) % 3 == b)
        cout << "KILLUA\n";
    else
        cout << "GON\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}