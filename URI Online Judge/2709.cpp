#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(long long n) {
    if (n < 2)
        return 0;
    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

bool solve() {
    int coinCount;
    if (!(cin >> coinCount))
        return 0;

    vector<int> coins(coinCount);
    for (int &coin : coins)
        cin >> coin;
    reverse(coins.begin(), coins.end());

    int jump;
    cin >> jump;

    int sum = 0;
    for (int i = 0; i < coinCount; i += jump)
        sum += coins[i];

    if (isPrime(sum))
        cout << "You’re a coastal aircraft, Robbie, a large silver aircraft.\n";
    else
        cout << "Bad boy! I’ll hit you.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}