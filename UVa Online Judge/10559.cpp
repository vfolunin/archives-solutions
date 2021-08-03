#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int l, int r, int rSize, vector<pair<int, int>> &blocks, vector<vector<vector<int>>> &memo) {
    int &res = memo[l][r][rSize];
    if (res != -1)
        return res;

    if (l > r)
        return res = 0;

    if (l == r)
        return res = rSize * rSize;

    res = rec(l, r - 1, blocks[r - 1].second, blocks, memo) + rSize * rSize;

    for (int pr = r - 1; pr >= l; pr--)
        if (blocks[pr].first == blocks[r].first)
            res = max(res, rec(l, pr, blocks[pr].second + rSize, blocks, memo) + rec(pr + 1, r - 1, blocks[r - 1].second, blocks, memo));

    return res;
}

void solve(int test) {
    int itemCount;
    cin >> itemCount;

    vector<pair<int, int>> blocks;
    for (int i = 0; i < itemCount; i++) {
        int type;
        cin >> type;

        if (blocks.empty() || blocks.back().first != type)
            blocks.push_back({ type, 1 });
        else
            blocks.back().second++;
    }

    vector<vector<vector<int>>> memo(blocks.size(), vector<vector<int>>(blocks.size(), vector<int>(itemCount + 1, -1)));
    int res = rec(0, blocks.size() - 1, blocks.back().second, blocks, memo);

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}