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

    int h, w;
    cin >> h >> w;

    const int MOD = 1e9 + 7;
    vector<int> fib = { 1, 1 };
    for (int i = 2; i <= h || i <= w; i++)
        fib.push_back((fib[i - 1] + fib[i - 2]) % MOD);

    cout << (fib[h] + fib[w] - 1) % MOD * 2 % MOD;
}