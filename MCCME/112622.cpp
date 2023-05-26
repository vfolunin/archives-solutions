#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int n, int last) {
    if (n < last)
        return 0;

    static vector<vector<int>> memo(10001, vector<int>(11, -1));
    int &res = memo[n][last];
    if (res != -1)
        return res;

    if (n == last)
        return res = 1;

    res = 0;
    for (int prev : { 1, 2, 5, 10 })
        if (prev <= last)
            res += rec(n - last, prev);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 0;
    for (int last : { 1, 2, 5, 10 })
        res += rec(n, last);

    cout << res;
}