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

    long long cur = 1, res = 1;

    for (int i = 0; i < n; i++) {
        int delta;
        cin >> delta;

        cur += delta;
        if (cur <= 0) {
            res += 1 - cur;
            cur = 1;
        }
    }

    cout << "Scenario #" << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}