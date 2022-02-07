#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int treeCount;
    cin >> treeCount;

    vector<int> trees(treeCount);
    for (int &tree : trees)
        cin >> tree;

    sort(trees.rbegin(), trees.rend());

    int res = 1;
    for (int i = 0; i < treeCount; i++)
        res = max(res, i + trees[i] + 2);

    cout << res << "\n";
}