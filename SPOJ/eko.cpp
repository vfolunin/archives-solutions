#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &trees, int height, long long targetSum) {
    long long sum = 0;
    for (int tree : trees)
        sum += max(0, tree - height);
    return sum >= targetSum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int treeCount;
    long long targetSum;
    cin >> treeCount >> targetSum;

    vector<int> trees(treeCount);
    for (int &tree : trees)
        cin >> tree;

    int l = 0, r = 2e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(trees, m, targetSum))
            l = m;
        else
            r = m;
    }

    cout << l;
}