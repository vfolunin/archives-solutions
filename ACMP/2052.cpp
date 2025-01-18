#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int n) {
    static vector<long long> memo(101, -1e18);
    long long &res = memo[n];
    if (res != -1e18)
        return res;

    if (n < 3)
        return res = 2;
    if (n % 2)
        return res = rec(n - 1) - rec(n - 2) + 2 * n;
    else
        return res = rec(n - 2) + rec(n - 1) - n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << rec(n);
}