#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<long long> fib = { 1, 1 };
    vector<long long> fact = { 1, 1 };
    vector<long long> two = { 1, 2 };

    for (int i = 2; i <= n; i++) {
        fib.push_back((fib[i - 2] + fib[i - 1]) % MOD);
        fact.push_back(fact[i - 1] * i % MOD);
        two.push_back(two[i - 1] * 2 % MOD);
    }

    cout << fib[n] * fact[n] % MOD * two[n] % MOD << "\n";
}