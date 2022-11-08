#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long c(int n, int k) {
    static vector<vector<long long>> memo(31, vector<long long>(31, -1));
    if (memo[n][k] != -1)
        return memo[n][k];

    if (k == 0 || k == n)
        return memo[n][k] = 1;

    return memo[n][k] = c(n - 1, k) + c(n - 1, k - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n, k;
    cin >> n >> k;

    cout << c(n, k);
}