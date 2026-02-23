#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1 % mod;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long opCount;
    string s;
    cin >> s >> opCount >> s;

    long long factor = binPow(2, opCount, s.size());

    for (int i = 0; i < s.size(); i++)
        cout << s[i * factor % s.size()];
}