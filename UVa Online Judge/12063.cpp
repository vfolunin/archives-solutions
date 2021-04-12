#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {   
    int n, divisor;
    cin >> n >> divisor;

    if (n % 2 || !divisor) {
        cout << "Case " << test << ": 0\n";
        return;
    }
    n /= 2;

    vector<vector<vector<long long>>> count(n + 1, vector<vector<long long>>(n + 1, vector<long long>(divisor)));
    count[0][1][1 % divisor] = 1;

    for (int k0 = 0; k0 <= n; k0++) {
        for (int k1 = 0; k1 <= n; k1++) {
            for (int mod = 0; mod < divisor; mod++) {
                if (k0 < n)
                    count[k0 + 1][k1][mod * 2 % divisor] += count[k0][k1][mod];
                if (k1 < n)
                    count[k0][k1 + 1][(mod * 2 + 1) % divisor] += count[k0][k1][mod];
            }
        }
    }

    cout << "Case " << test << ": " << count[n][n][0] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}