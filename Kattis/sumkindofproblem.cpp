#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> prepare() {
    vector<vector<int>> sums(3, vector<int>(1));
    for (int i = 1; i <= 1e4; i++) {
        sums[0].push_back(sums[0].back() + i);
        sums[1].push_back(sums[1].back() + i * 2 - 1);
        sums[2].push_back(sums[2].back() + i * 2);
    }
    return sums;
}

void solve() {
    int test, n;
    cin >> test >> n;

    static vector<vector<int>> sums = prepare();

    cout << test << " ";
    for (vector<int> &sum : sums)
        cout << sum[n] << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}