#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

void rec(int product, int from, vector<int> &powers, double &minRes, long long &minResMod) {
    if (product == 1) {
        static vector<int> primes = { 2, 3, 5, 7, 11, 13, 17 };
        
        double res = 1;
        long long resMod = 1;
        for (int i = 0; i < powers.size(); i++) {
            for (int j = 0; j < powers[powers.size() - 1 - i] - 1; j++) {
                res *= primes[i];
                resMod = resMod * primes[i] % MOD;
            }
        }
        
        if (minRes > res) {
            minRes = res;
            minResMod = resMod;
        }
        return;
    }

    for (int d = from; d <= product; d++) {
        if (product % d == 0) {
            powers.push_back(d);
            rec(product / d, d, powers, minRes, minResMod);
            powers.pop_back();
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> powers;
    double res = 1e100;
    long long resMod = 0;
    rec(n, 2, powers, res, resMod);

    cout << resMod << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}