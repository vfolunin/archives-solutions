#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int partitionCount(int n, int parts, int from) {
    static vector<vector<vector<int>>> memo(221, vector<vector<int>>(11, vector<int>(221, -1)));
    int &res = memo[n][parts][from];
    if (res != -1)
        return res;

    if (from > n)
        return res = 0;

    if (parts == 1)
        return res = (n == from);

    res = 0;
    for (int nextPart = from; nextPart <= n - from; nextPart++)
        res += partitionCount(n - from, parts - 1, nextPart);
    return res;
}

void solve() {
    int n, parts, index;
    cin >> n >> parts >> index;
    index--;

    int part = 1;
    while (parts) {
        while (index >= partitionCount(n, parts, part)) {
            index -= partitionCount(n, parts, part);
            part++;
        }
        cout << part << "\n";
        n -= part;
        parts--;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}