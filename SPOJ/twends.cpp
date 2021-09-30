#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<int> &a, int l, int r, vector<vector<int>> &memo) {
    int &res = memo[l][r];
    if (res != -1)
        return res;

    if (l + 1 == r)
        return res = max(a[l], a[r]) - min(a[l], a[r]);

    int lRes = a[l];
    if (a[l + 1] >= a[r])
        lRes += rec(a, l + 2, r, memo) - a[l + 1];
    else
        lRes += rec(a, l + 1, r - 1, memo) - a[r];

    int rRes = a[r];
    if (a[l] >= a[r - 1])
        rRes += rec(a, l + 1, r - 1, memo) - a[l];
    else
        rRes += rec(a, l, r - 2, memo) - a[r - 1];

    return res = max(lRes, rRes);
}

bool solve(int test) {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    vector<vector<int>> memo(size, vector<int>(size, -1));
    int res = rec(a, 0, size - 1, memo);

    cout << "In game " << test << ", the greedy strategy ";
    cout << "might lose by as many as " << res << " points.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}