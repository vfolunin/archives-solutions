#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<long long> ways = { 1, 1, 2 };
    for (int i = 3; i <= n; i++)
        ways.push_back((ways[i - 3] + ways[i - 2] + ways[i - 1]) % MOD);

    cout << ways[n] << "\n";
}