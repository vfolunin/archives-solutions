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

    int n, mod;
    cin >> n >> mod;

    if (n >= mod) {
        cout << 0;
        return 0;
    }

    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i % mod;

    cout << res;
}