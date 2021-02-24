#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    char val;
    Node *l, *r;
    Node() : l(0), r(0) {}
};

void reconstruct(Node *n, string &preorder, int &pi, string &inorder, int il, int ir) {
    if (il == ir) {
        n->val = preorder[pi++];
        return;
    }
    n->val = preorder[pi];
    if (il < ir) {
        int im = inorder.find(preorder[pi++]);
        if (il < im)
            reconstruct(n->l = new Node(), preorder, pi, inorder, il, im - 1);
        if (im < ir)
            reconstruct(n->r = new Node(), preorder, pi, inorder, im + 1, ir);
    }
}

void postorder(Node *n) {
    if (!n)
        return;
    postorder(n->l);
    postorder(n->r);
    cout << n->val;
}

void solve() {
    int n;
    string preorder, inorder;
    cin >> n >> preorder >> inorder;

    Node *root = new Node();
    int pi = 0;
    reconstruct(root, preorder, pi, inorder, 0, inorder.size() - 1);
    postorder(root);
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}