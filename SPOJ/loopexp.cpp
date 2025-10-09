#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<double> prepare() {
    vector<double> res(1e5 + 1);
    res[1] = 1;
    for (int i = 2; i < res.size(); i++)
        res[i] = res[i - 1] + 1.0 / i;
    return res;
}

void solve() {
    double n;
    cin >> n;

    static vector<double> res = prepare();

    cout << fixed << res[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}