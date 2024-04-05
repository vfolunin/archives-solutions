#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    char value;
    Node *left = 0, *right = 0;
};

Node *reconstruct(string &preorder, int &pi, string &inorder, int il, int ir) {
    Node *n = new Node();
    n->value = preorder[pi++];

    if (il < ir) {
        int im = find(inorder.begin() + il, inorder.begin() + ir + 1, n->value) - inorder.begin();
        if (il < im)
            n->left = reconstruct(preorder, pi, inorder, il, im - 1);
        if (im < ir)
            n->right = reconstruct(preorder, pi, inorder, im + 1, ir);
    }

    return n;
}

void traverse(Node *n) {
    if (!n)
        return;

    traverse(n->left);
    traverse(n->right);
    cout << n->value;
}

void solve() {
    int size;
    string preorder, inorder;
    cin >> size >> preorder >> inorder;

    int pi = 0;
    traverse(reconstruct(preorder, pi, inorder, 0, size - 1));
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