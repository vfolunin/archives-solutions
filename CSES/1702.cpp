#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    int val;
    Node *l, *r;
    Node() : l(0), r(0) {}
};

void reconstruct(Node *n, vector<int> &preorder, int &pi, vector<int> &posInInorder, int il, int ir) {
    n->val = preorder[pi++];

    if (il == ir)
        return;

    int im = posInInorder[n->val];
    if (il < im)
        reconstruct(n->l = new Node(), preorder, pi, posInInorder, il, im - 1);
    if (im < ir)
        reconstruct(n->r = new Node(), preorder, pi, posInInorder, im + 1, ir);
}

void postorder(Node *n) {
    if (!n)
        return;
    postorder(n->l);
    postorder(n->r);
    cout << n->val << " ";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> preorder(n);
    for (int &x : preorder)
        cin >> x;

    vector<int> posInInorder(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        posInInorder[x] = i;
    }

    Node *root = new Node();
    int pi = 0;
    reconstruct(root, preorder, pi, posInInorder, 0, n - 1);

    postorder(root);
}