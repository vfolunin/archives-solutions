#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<vector<int>>> prepare() {
    int N = 5e4 + 1;
    vector<vector<vector<int>>> res(4, vector<vector<int>>(N));

    for (int i = 0; i * i < N; i++)
        res[1][i * i] = { i };

    for (int i = 0; i * i < N; i++)
        for (int sum = i * i; sum < N; sum++)
            if (res[2][sum].empty() && !res[1][sum - i * i].empty())
                res[2][sum] = { res[1][sum - i * i][0], i };

    for (int i = 0; i * i < N; i++)
        for (int sum = i * i; sum < N; sum++)
            if (res[3][sum].empty() && !res[2][sum - i * i].empty())
                res[3][sum] = { res[2][sum - i * i][0], res[2][sum - i * i][1], i };

    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<vector<int>> res = prepare()[3];

    if (!res[n].empty())
        cout << res[n][2] << " " << res[n][1] << " " << res[n][0] << "\n";
    else
        cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}