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

    int getMinHeight(Node *n) {
        if (!n->l && !n->r)
            return 1;
        else if (!n->l)
            return getMinHeight(n->r) + 1;
        else if (!n->r)
            return getMinHeight(n->l) + 1;
        else
            return min(getMinHeight(n->l), getMinHeight(n->r)) + 1;
    }

    int getMinHeight() {
        return getMinHeight(root);
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

    cout << bst.getMinHeight();
}