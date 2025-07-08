#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    const long long MOD = 1e9 + 7;
    vector<long long> res = { 0, 1 };
    for (int i = 2; i < 1e6; i++)
        res.push_back(((5 * res[i - 1] * res[i - 1] - 3 * res[i - 2]) % MOD + MOD) % MOD);
    return res;
}

void solve() {
    int index;
    cin >> index;

    static vector<long long> res = prepare();

    cout << res[index] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}