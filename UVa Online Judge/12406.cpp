#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int len, pow;
    cin >> len >> pow;

    cout << "Case " << test << ":";

    bool hasOutput = 0;
    for (int mask = 0; mask < (1 << len); mask++) {
        long long num = 0;
        for (int bit = len - 1; bit >= 0; bit--)
            num = num * 10 + ((mask & (1 << bit)) ? 2 : 1);

        if (num % (1 << pow) == 0) {
            hasOutput = 1;
            cout << " " << num;
        }
    }

    if (!hasOutput)
        cout << " impossible";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}