#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int size, int inversionCount) {
    static vector<vector<long long>> memo(21, vector<long long>(401, -1));
    long long &res = memo[size][inversionCount];
    if (res != -1)
        return res;

    if (size == 1)
        return res = !inversionCount;

    res = 0;
    for (int last = 0; last < size && last <= inversionCount; last++)
        res += rec(size - 1, inversionCount - last);
    return res;
}

void solve() {
    int size, inversionCount;
    cin >> size >> inversionCount;

    cout << rec(size, inversionCount) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}