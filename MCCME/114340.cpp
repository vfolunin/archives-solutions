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

    int n;
    cin >> n;

    vector<int> ways(n + 1);
    ways[0] = 1;

    const int MOD = 1e9 + 7;
    for (int last = 1; last <= n; last++)
        for (int sum = last; sum <= n; sum++)
            ways[sum] = (ways[sum] + ways[sum - last]) % MOD;

    cout << ways[n];
}