#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7, INV2 = 5e8 + 4;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;
    if (sum % 2) {
        cout << 0;
        return 0;
    }
    sum /= 2;

    vector<long long> ways(sum + 1);
    ways[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int s = sum; s >= i; s--)
            ways[s] = (ways[s] + ways[s - i]) % MOD;

    cout << ways[sum] * INV2 % MOD;
}