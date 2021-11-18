#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

    void insert(int key) {
        insert(root, key);
    }

    void levelOrder() {
        queue<Node *> q;
        if (root)
            q.push(root);

        while (!q.empty()) {
            Node *n = q.front();
            q.pop();

            cout << (n == root ? "" : " ") << n->key;

            if (n->l)
                q.push(n->l);
            if (n->r)
                q.push(n->r);
        }
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
    bst.levelOrder();
    cout << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}