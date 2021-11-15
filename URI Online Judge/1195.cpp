#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BST {
    struct Node {
        int key;
        Node *l = 0, *r = 0;
        Node(int key) : key(key) {}
    } *root = 0;

    void insert(Node *&n, int key) {
        if (!n) {
            n = new Node(key);
            return;
        }
        if (key < n->key)
            insert(n->l, key);
        else
            insert(n->r, key);
    }

    void preorder(Node *n) {
        if (!n)
            return;
        cout << " " << n->key;
        preorder(n->l);
        preorder(n->r);
    }

    void inorder(Node *n) {
        if (!n)
            return;
        inorder(n->l);
        cout << " " << n->key;
        inorder(n->r);
    }

    void postorder(Node *n) {
        if (!n)
            return;
        postorder(n->l);
        postorder(n->r);
        cout << " " << n->key;
    }

    void insert(int key) {
        insert(root, key);
    }

    void preorder() {
        preorder(root);
    }

    void inorder() {
        inorder(root);
    }

    void postorder() {
        postorder(root);
    }
};

void solve(int test) {
    int n;
    cin >> n;

    BST bst;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bst.insert(x);
    }

    cout << "Case " << test << ":\n";
    cout << "Pre.:";
    bst.preorder();
    cout << "\nIn..:";
    bst.inorder();
    cout << "\nPost:";
    bst.postorder();
    cout << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}