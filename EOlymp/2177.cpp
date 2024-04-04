#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return rec(20, 20, 20);

    static vector<vector<vector<long long>>> memo(21, vector<vector<long long>>(21, vector<long long>(21, 1e18)));
    long long &res = memo[a][b][c];
    if (res != 1e18)
        return res;

    if (a < b && b < c)
        return res = rec(a, b, c - 1) + rec(a, b - 1, c - 1) - rec(a, b - 1, c);
    else
        return res = rec(a - 1, b, c) + rec(a - 1, b - 1, c) + rec(a - 1, b, c - 1) - rec(a - 1, b - 1, c - 1);
}

bool solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == -1 && b == -1 && c == -1)
        return 0;

    cout << "w(" << a << ", " << b << ", " << c << ") = " << rec(a, b, c) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}