#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int n) {
    static vector<long long> memo(1e4 + 1, -1e18);
    long long &res = memo[n];
    if (res != -1e18)
        return res;

    if (n == 1)
        return res = 1;
    else
        return res = n - 2 + rec(n - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int r, l;
    cin >> r >> l;

    for (int i = 1; i <= 1e4; i++)
        rec(i);

    cout << rec(r) - rec(l);
}