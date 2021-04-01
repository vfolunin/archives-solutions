#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> res(41);
    res[0] = 1;
    res[1] = 1;
    res[2] = 5;
    for (int i = 3; i < res.size(); i++)
        res[i] = res[i - 1] + 4 * res[i - 2] + 2 * res[i - 3];
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