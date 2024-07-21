#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int recSmall(int n) {
    static vector<int> memo(1e7, -1);
    int &res = memo[n];
    if (res != -1)
        return res;

    if (n == 1)
        return res = 0;

    res = 1e9;
    if (n % 3 == 0)
        res = min(res, recSmall(n / 3) + 5);
    if (n > 4)
        res = min(res, recSmall(n - 4) + 2);
    return res;
}

int rec(int n) {
    if (n < 1e7)
        return recSmall(n);

    static unordered_map<int, int> memo;
    if (memo.count(n))
        return memo[n];
    int &res = memo[n];

    res = 1e9;
    if (n % 3 == 0)
        res = min(res, rec(n / 3) + 5);
    else
        res = min(res, rec(n - 4) + 2);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < 1e7; i++)
        rec(i);

    cout << (rec(n) < 1e9 ? rec(n) : 0);
}