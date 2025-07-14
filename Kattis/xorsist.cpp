#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    long long res = 0;
    for (int bit = 0; bit < 62; bit++) {
        long long period = 1LL << (bit + 1);
        long long periodCount = (n + 1) / period;
        long long onesInPeriod = 1LL << bit;
        long long remainder = (n + 1) % period;
        long long onesInRemainder = max(remainder - period / 2, 0LL);
        res |= ((periodCount * onesInPeriod + onesInRemainder) % 2) << bit;
    }

    if (!res)
        cout << "Enginn";
    else if (res > n)
        cout << "Gunnar";
    else
        cout << res;
}