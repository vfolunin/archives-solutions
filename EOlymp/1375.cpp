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

    if (!n) {
        cout << "Case #" << test << ": 0\n";
        return;
    }

    string res;
    while (n) {
        int mod = n - n / -2 * -2;
        if (mod < 0)
            mod += 2;
        res += mod + '0';
        n = (n - mod) / -2;
    }

    reverse(res.begin(), res.end());
    cout << "Case #" << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}