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

    bool equal(Node *a, Node *b) {
        if (!a || !b)
            return !a && !b;
        return a->key == b->key && equal(a->l, b->l) && equal(a->r, b->r);
    }

    bool equalTo(BST &that) {
        return equal(root, that.root);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int aSize;
    cin >> aSize;

    BST a;
    for (int i = 0; i < aSize; i++) {
        int value;
        cin >> value;

        a.insert(value);
    }

    int bSize;
    cin >> bSize;

    BST b;
    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;

        b.insert(value);
    }

    cout << a.equalTo(b);
}