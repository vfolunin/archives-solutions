#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcdOps(int a, int b) {
    if (!b)
        return 0;
    if (a < b)
        return gcdOps(b, a);
    return a / b + gcdOps(b, a % b);
}

void solve() {
    int a, b;
    cin >> a >> b;

    cout << gcdOps(a, b) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}