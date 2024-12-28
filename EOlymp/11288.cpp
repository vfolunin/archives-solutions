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

    int size;
    cin >> size;

    const long long MOD = 1e9 + 7;
    vector<long long> ways(size + 1);
    ways[0] = ways[1] = 1;
    for (int i = 2; i < ways.size(); i++)
        ways[i] = (ways[i - 1] + (i - 1) * ways[i - 2]) % MOD;

    cout << ways[size];
}