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

void traverse(vector<Node> &nodes, int i, vector<int> &values) {
    if (i == -1)
        return;

    traverse(nodes, nodes[i].l, values);
    values.push_back(nodes[i].value);
    traverse(nodes, nodes[i].r, values);
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

    vector<int> values;
    traverse(nodes, root, values);

    cout << values[values.size() - 2];
}