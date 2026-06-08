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

    if ((a + b + c) % 3 || b > (a + b + c) / 3)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}