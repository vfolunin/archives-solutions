#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    int val;
    Node *l = 0, *r = 0;
};

void construct(Node *n, vector<int> &vals, int l, int r) {
    n->val = vals[l];

    int i = l + 1;
    while (i <= r && vals[i] < vals[l])
        i++;

    if (l + 1 < i)
        construct(n->l = new Node(), vals, l + 1, i - 1);
    if (i <= r)
        construct(n->r = new Node(), vals, i, r);
}

void postorder(Node *n) {
    if (!n)
        return;
    postorder(n->l);
    postorder(n->r);
    cout << n->val << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> vals;
    while (1) {
        int val;
        if (!(cin >> val))
            break;
        vals.push_back(val);
    }

    Node root;
    construct(&root, vals, 0, vals.size() - 1);
    postorder(&root);
}