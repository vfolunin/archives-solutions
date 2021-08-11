#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int size, int strikeLimit) {
    static vector<vector<int>> memo(1001, vector<int>(21, -1));
    int &res = memo[size][strikeLimit];
    if (res != -1)
        return res;

    if (!size)
        return res = 0;

    if (!strikeLimit)
        return res = size;

    res = 1e9;
    for (int i = 0; i < size; i++)
        res = min(res, 1 + max(rec(i, strikeLimit - 1), rec(size - 1 - i, strikeLimit)));
    return res;
}

void solve() {
    int size, strikeLimit;
    cin >> size >> strikeLimit;

    cout << rec(size, strikeLimit - 1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}