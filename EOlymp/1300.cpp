#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> res = { 0, 0 };
    for (long long i = 0; i < 1e6; i++)
        res.push_back(res.back() + (i / 2) * ((i + 1) / 2));
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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}