#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int a, int b, int c) {
    static map<vector<int>, int> memo;
    if (memo.count({ a, b, c }))
        return memo[{ a, b, c }];
    int &res = memo[{ a, b, c }];

    res = 0;
    if (a + 1 < b) {
        if ((b - a) % 2)
            res = max(res, 1 + rec(a, (a + b) / 2 + 1, b));
        res = max(res, 1 + rec(a, (a + b) / 2, b));
    }
    if (b + 1 < c) {
        if ((c - b) % 2)
            res = max(res, 1 + rec(b, (b + c) / 2 + 1, c));
        res = max(res, 1 + rec(b, (b + c) / 2, c));
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;

    cout << rec(a, b, c);
}