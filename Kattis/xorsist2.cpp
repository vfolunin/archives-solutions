#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getXor(long long n) {
    long long res = 0;
    for (int bit = 0; bit < 62; bit++) {
        long long period = 1LL << (bit + 1);
        long long periodCount = (n + 1) / period;
        long long onesInPeriod = 1LL << bit;
        long long remainder = (n + 1) % period;
        long long onesInRemainder = max(remainder - period / 2, 0LL);
        res |= ((periodCount * onesInPeriod + onesInRemainder) % 2) << bit;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n, l, r;
    cin >> n >> l >> r;

    long long res = getXor(r) ^ getXor(l - 1);

    if (!res)
        cout << "Enginn";
    else if (res > n)
        cout << "Gunnar";
    else
        cout << res;
}