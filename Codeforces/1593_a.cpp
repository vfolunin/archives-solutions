#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << max(0, max(b, c) + 1 - a) << " ";
    cout << max(0, max(a, c) + 1 - b) << " ";
    cout << max(0, max(a, b) + 1 - c) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}