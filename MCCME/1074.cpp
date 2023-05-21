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

int rec(vector<Node> &nodes, int i) {
    if (i == -1)
        return 0;

    return rec(nodes, nodes[i].l) + nodes[i].value + rec(nodes, nodes[i].r);
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

    cout << rec(nodes, root);
}