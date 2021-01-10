#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    long long dist = abs(a - b);
    cout << (long long)sqrt(max(0LL, 4 * dist - 3)) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}