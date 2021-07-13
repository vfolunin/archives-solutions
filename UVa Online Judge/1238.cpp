#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<char> ops;
    vector<int> args(1);
    if (!(cin >> args.back()))
        return 0;

    while (cin.peek() == ' ') {
        ops.emplace_back();
        args.emplace_back();
        cin >> ops.back() >> args.back();
    }

    vector<vector<unordered_set<int>>> res(args.size(), vector<unordered_set<int>>(args.size()));
    for (int i = 0; i < args.size(); i++)
        res[i][i] = { args[i] };
    for (int len = 2; len <= args.size(); len++)
        for (int l = 0, r = len - 1; r < args.size(); l++, r++)
            for (int m = l; m < r; m++)
                for (int v1 : res[l][m])
                    for (int v2 : res[m + 1][r])
                        res[l][r].insert(ops[m] == '+' ? v1 + v2 : v1 - v2);

    cout << res[0][args.size() - 1].size() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}