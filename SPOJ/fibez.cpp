#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    const int MOD = 1e8 + 7;
    vector<int> res = { 0, 1 };
    for (int i = 2; i <= 5e5; i++)
        res.push_back((res[i - 2] + res[i - 1]) % MOD);
    return res;
}

void solve() {
    int index;
    cin >> index;

    static vector<int> res = prepare();

    cout << res[index] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}