#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    cin >> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x = 0;
    for (int i = 0; i < n; i += 2)
        x ^= a[i + 1] - a[i];

    cout << "Case " << test << ": " << (x ? "First" : "Second") << " Player\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}