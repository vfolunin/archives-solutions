#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(1001, 1e9);
    res[0] = 0;

    for (int i = 1; i < res.size(); i++)
        for (int j = 1; j * j <= i; j++)
            res[i] = min(res[i], res[i - j * j] + 1);

    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> res = prepare();

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