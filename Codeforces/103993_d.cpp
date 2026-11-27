#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long c(int n, int k) {
    static vector<vector<long long>> memo(20, vector<long long>(20, -1));
    long long &res = memo[n][k];
    if (res != -1)
        return res;

    if (k == 0 || k == n)
        return res = 1;

    return res = c(n - 1, k) + c(n - 1, k - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << c(10 - n, 2) * c(6, 3);
}