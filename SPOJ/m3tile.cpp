#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<vector<int>> ways(31, vector<int>(8));
    ways[0][0] = ways[0][3] = ways[0][6] = 1;

    for (int i = 1; i < ways.size(); i++) {
        ways[i][0] = ways[i - 1][7];
        ways[i][1] = ways[i - 1][6];
        ways[i][2] = ways[i - 1][5];
        ways[i][3] = ways[i - 1][4] + ways[i - 1][7];
        ways[i][4] = ways[i - 1][3];
        ways[i][5] = ways[i - 1][2];
        ways[i][6] = ways[i - 1][1] + ways[i - 1][7];
        ways[i][7] = ways[i - 1][0] + ways[i - 1][3] + ways[i - 1][6];
    }

    vector<int> res(ways.size());
    for (int i = 0; i < res.size(); i++)
        res[i] = ways[i][0];
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (n == -1)
        return 0;

    static vector<int> res = prepare();
    cout << res[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}