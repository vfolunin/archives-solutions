#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

bool solve() {
    int coinCount, tableCount;
    cin >> coinCount >> tableCount;

    if (!coinCount)
        return 0;

    vector<long long> coins(coinCount);
    for (long long &coin : coins)
        cin >> coin;

    set<long long> lcms;
    for (int a = 0; a < coinCount; a++)
        for (int b = a + 1; b < coinCount; b++)
            for (int c = b + 1; c < coinCount; c++)
                for (int d = c + 1; d < coinCount; d++)
                    lcms.insert(lcm(lcm(coins[a], coins[b]), lcm(coins[c], coins[d])));

    for (int i = 0; i < tableCount; i++) {
        long long height;
        cin >> height;

        long long l = 0, r = 1e18;
        for (long long m : lcms) {
            l = max(l, height / m * m);
            r = min(r, (height + m - 1) / m * m);
        }
        cout << l << " " << r << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}