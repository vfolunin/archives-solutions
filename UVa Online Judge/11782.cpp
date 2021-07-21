#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<int> &tree, int i, int size, vector<vector<int>> &res) {
    res[i][1] = tree[i];

    if (size > 1) {
        int l = i + 1, r = i + 1 + size / 2;
        dfs(tree, l, size / 2, res);
        dfs(tree, r, size / 2, res);

        for (int size = 2; size < res[i].size(); size++)
            for (int lSize = 1, rSize = size - 1; lSize < size; lSize++, rSize--)
                res[i][size] = max(res[i][size], res[l][lSize] + res[r][rSize]);
    }
}

bool solve() {
    int height, maxSize;
    if (!(cin >> height >> maxSize))
        return 0;

    vector<int> tree((1 << (height + 1)) - 1);
    for (int &v : tree)
        cin >> v;

    vector<vector<int>> res(tree.size(), vector<int>(maxSize + 1, -1e9));
    dfs(tree, 0, tree.size(), res);

    cout << *max_element(res[0].begin(), res[0].end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}