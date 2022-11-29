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
        else if (key > n->key)
            insert(n->r, key);
        else
            return;
    }

    void insert(int key) {
        insert(root, key);
    }

    pair<bool, int> balanced(Node *n) {
        if (!n)
            return { 1, 0 };

        auto [lBalanced, lHeight] = balanced(n->l);
        auto [rBalanced, rHeight] = balanced(n->r);

        if (lBalanced && rBalanced && abs(lHeight - rHeight) <= 1)
            return { 1, max(lHeight, rHeight) + 1 };
        else
            return { 0, 0 };
    }

    bool balanced() {
        return balanced(root).first;
    }
};


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BST bst;

    while (true) {
        int value;
        cin >> value;

        if (value == 0)
            break;

        bst.insert(value);
    }

    cout << (bst.balanced() ? "YES" : "NO");
}