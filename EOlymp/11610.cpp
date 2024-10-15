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

    const long long MOD = 1e9 + 7;
    long long res = 1;

    for (char c; cin >> c; )
        if (isupper(c))
            res = res * (c - 'A' + 1) % MOD;

    cout << res;
}