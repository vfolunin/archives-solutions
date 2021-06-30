#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res = { 0, 1, 1, 3, 3, 8 };
    for (int i = 6; i < 40; i++)
        res.push_back(res[i - 1] + 3 * res[i - 2] - res[i - 3] - 2 * res[i - 5] - 4 * res[i - 6]);
    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> res = prepare();

    cout << res[n + 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
