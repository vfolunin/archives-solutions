#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 9;
const long long INV = 833333341;

vector<long long> prepare() {
    vector<long long> f = { 1 };
    for (int i = 1; i <= 1e5; i++)
        f.push_back(f.back() * i % MOD);
    return f;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<long long> f = prepare();

    cout << f[n] * INV % MOD << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}