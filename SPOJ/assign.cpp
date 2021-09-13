#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int studentCount, int mask, vector<vector<int>> &can, vector<vector<long long>> &memo) {
    long long &res = memo[studentCount][mask];
    if (res != -1)
        return res;

    if (!studentCount)
        return res = 1;

    res = 0;
    for (int bit = 0; bit < can.size(); bit++)
        if ((mask & (1 << bit)) && can[studentCount - 1][bit])
            res += rec(studentCount - 1, mask ^ (1 << bit), can, memo);
    return res;
}

void solve() {
    int studentCount;
    cin >> studentCount;

    vector<vector<int>> can(studentCount, vector<int>(studentCount));
    for (vector<int> &row : can)
        for (int &x : row)
            cin >> x;

    vector<vector<long long>> memo(studentCount + 1, vector<long long>(1 << studentCount, -1));
    long long res = rec(studentCount, (1 << studentCount) - 1, can, memo);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}