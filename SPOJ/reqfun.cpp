#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> prepare() {
    vector<vector<int>> res(15, vector<int>(15));

    for (int j = 0; j < res[0].size(); j++)
        res[0][j] = j;

    for (int i = 1; i < res.size(); i++)
        for (int j = 0; j < res[0].size(); j++)
            for (int k = 0; k <= j; k++)
                res[i][j] += res[i - 1][k];
    
    return res;
}

void solve() {
    int i, j;
    cin >> i >> j;

    static vector<vector<int>> res = prepare();

    cout << res[i][j] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}