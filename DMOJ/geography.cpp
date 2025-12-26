#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> res(1e5 + 1);
    for (long long d = 1; d < res.size(); d++)
        for (int value = d; value < res.size(); value += d)
            res[value] += d * d;
    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<long long> res = prepare();

    cout << res[n] << "\n";
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