#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int UNKNOWN = 2e9, NO = -2e9;

int rec(vector<vector<int>> &a, int y, int x, int neg, vector<vector<vector<int>>> &memo) {
    int &res = memo[y][x][neg];
    if (res != UNKNOWN)
        return res;

    res = NO;

    if (!y) {
        int sum = 0, realNeg = 0;
        for (int j = 0; j <= x; j++) {
            sum += a[y][j];
            realNeg += a[y][j] < 0;
        }
        if (realNeg == neg)
            res = sum;
        return res;
    }

    for (int px = 0; px < a.size(); px++) {
        int l = min(px, x), r = max(px, x);
        int sum = 0, realNeg = 0;
        for (int j = l; j <= r; j++) {
            sum += a[y][j];
            realNeg += a[y][j] < 0;
        }
        if (realNeg <= neg && rec(a, y - 1, px, neg - realNeg, memo) != NO)
            res = max(res, rec(a, y - 1, px, neg - realNeg, memo) + sum);
    }
    return res;
}

bool solve(int test) {
    int size, neg;
    cin >> size >> neg;

    if (!size)
        return 0;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    vector<vector<vector<int>>> memo(size, vector<vector<int>>(size, vector<int>(neg + 1, UNKNOWN)));
    int res = NO;
    for (int n = 0; n <= neg; n++)
        res = max(res, rec(a, size - 1, size - 1, n, memo));

    cout << "Case " << test << ": ";
    if (res != NO)
        cout << res << "\n";
    else
        cout << "impossible\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}