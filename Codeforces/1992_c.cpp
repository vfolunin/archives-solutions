#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = n; i > m; i--)
        cout << i << " ";
    for (int i = 1; i <= m; i++)
        cout << i << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}