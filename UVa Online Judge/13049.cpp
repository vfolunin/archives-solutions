#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    string a, b;
    cin >> n >> a >> b;

    int res = 0;
    for (int i = 0; i < n; i++) {
        int diff = abs(a[i] - b[i]);
        res += min(diff, 10 - diff);
    }

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}