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

void traverse(vector<Node> &nodes, int i) {
    if (i == -1)
        return;

    traverse(nodes, nodes[i].l);
    if (nodes[i].l == -1 && nodes[i].r == -1)
        cout << nodes[i].value << "\n";
    traverse(nodes, nodes[i].r);
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

    traverse(nodes, root);
}