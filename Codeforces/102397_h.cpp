#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

long long binPow(long long x, long long p) {
    if (!p)
        return 1;
    if (p)
        return binPow(x, p - 1) * x % MOD;
    long long r = binPow(x, p / 2);
    return r * r % MOD;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    long long res = 0;
    for (auto &[_, count] : count)
        res += (binPow(2, count) + MOD - 1) % MOD;

    cout << res;
}