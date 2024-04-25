#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getCatalan(int n, int mod) {
    vector<long long> res = { 1 % mod };
    for (int i = 1; i <= n; i++) {
        res.push_back(0);
        for (int j = 0; j < i; j++)
            res.back() = (res.back() + res[j] * res[i - 1 - j] % mod) % mod;
    }
    return res.back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, mod;
    cin >> n >> mod;

    cout << getCatalan(n, mod);
}