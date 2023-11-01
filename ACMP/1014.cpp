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

    const long long MOD = 1e9 + 9;
    vector<long long> ways(n + 1);
    ways[2] = 1;

    for (int i = 3; i <= n; i++)
        ways[i] = (i - 1) * (ways[i - 1] + ways[i - 2]) % MOD;

    cout << ways[n];
}