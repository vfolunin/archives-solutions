#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

long long inv(long long x) {
    return binPow(x, MOD - 2, MOD);
}

vector<long long> getF() {
    vector<long long> f(1e6 + 1);
    f[0] = 1;
    for (int i = 1; i < f.size(); i++)
        f[i] = f[i - 1] * i % MOD;
    return f;
}

bool solve() {
    string word;
    if (!(cin >> word))
        return 0;

    map<char, int> letterCount;
    for (char letter : word)
        letterCount[letter]++;

    static vector<long long> f = getF();

    long long res = f[word.size()];
    for (auto &[_, count] : letterCount)
        res = res * inv(f[count]) % MOD;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}