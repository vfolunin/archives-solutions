#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long fib(int n, int mod) {
    static vector<long long> memo(501, -1);
    long long &res = memo[n];
    if (res != -1)
        return res;

    if (n == 0)
        return res = 2 % mod;
    if (n == 1)
        return res = 3 % mod;
    return res = (fib(n - 1, mod) + fib(n - 2, mod)) % mod;
}

long long f(int x, int y, int mod) {
    if (x <= 0 || y <= 0)
        return 0;

    static vector<vector<long long>> memo(501, vector<long long>(501, -1));
    long long &res = memo[x][y];
    if (res != -1)
        return res;

    if (x <= y)
        return res = (f(x - 1, y - 2, mod) + f(x - 2, y - 1, mod) + fib(x, mod)) % mod;
    else
        return res = (f(x - 2, y - 2, mod) + fib(y, mod)) % mod;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y, mod;
    cin >> x >> y >> mod;

    cout << f(x, y, mod);
}