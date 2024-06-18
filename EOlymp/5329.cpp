#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 9929;

long long c(int n, int k) {
    static vector<vector<long long>> memo(1000, vector<long long>(1000, -1));
    long long &res = memo[n][k];
    if (res != -1)
        return res;

    if (k == 0 || k == n)
        return res = 1;

    return res = (c(n - 1, k) + c(n - 1, k - 1)) % MOD;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    cout << c(n, k);
}