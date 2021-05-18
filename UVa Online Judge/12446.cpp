#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

vector<long long> prepare() {
    const int N = 1e6 + 1;

    vector<long long> res(N);
    res[0] = 1;
    res[1] = 2;
    res[2] = 9;

    for (int i = 3; i < N; i++)
        res[i] = ((3 * res[i - 1] + 3 * res[i - 2] - res[i - 3]) % MOD + MOD) % MOD;

    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<long long> res = prepare();

    cout << res[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}