#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    int value, l, r;
};

pair<bool, int> rec(vector<Node> &nodes, int i) {
    if (i == -1)
        return { 1, 0 };

    auto [lBalanced, lHeight] = rec(nodes, nodes[i].l);
    auto [rBalanced, rHeight] = rec(nodes, nodes[i].r);
    return { lBalanced && rBalanced && abs(lHeight - rHeight) <= 1, max(lHeight, rHeight) + 1 };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int nodeCount;
    cin >> nodeCount;

    vector<Node> nodes(nodeCount);
    for (auto &[value, l, r] : nodes) {
        cin >> l >> r >> value;
        l--;
        r--;
    }

    int root;
    cin >> root;
    root--;

    cout << (rec(nodes, root).first ? "YES" : "NO");
}