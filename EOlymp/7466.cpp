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

    void insert(int key) {
        insert(root, key);
    }

    pair<bool, int> isBalanced(Node *n) {
        if (!n)
            return { 1, 0 };
        auto [lBalanced, lHeight] = isBalanced(n->l);
        auto [rBalanced, rHeight] = isBalanced(n->r);
        return { lBalanced && rBalanced && abs(lHeight - rHeight) <= 1, max(lHeight, rHeight) + 1 };
    }

    bool isBalanced() {
        return isBalanced(root).first;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    BST bst;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        bst.insert(value);
    }

    cout << bst.isBalanced();
}