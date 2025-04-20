#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

class Treap {
    static minstd_rand gen;

    struct Node {
        int key, priority, size = 1;
        Node *left = 0, *right = 0;
        Node(int key) : key(key), priority(gen()) {}
    } *root = 0;

    int getSize(Node *n) const {
        return n ? n->size : 0;
    }

    void update(Node *n) {
        if (n)
            n->size = getSize(n->left) + 1 + getSize(n->right);
    }

    Node *merge(Node *a, Node *b) {
        if (!a || !b)
            return a ? a : b;
        if (a->priority > b->priority) {
            a->right = merge(a->right, b);
            update(a);
            return a;
        } else {
            b->left = merge(a, b->left);
            update(b);
            return b;
        }
    }

    void split(Node *t, int key, Node *&a, Node *&b) {
        if (!t) {
            a = b = 0;
            return;
        }
        if (t->key < key) {
            split(t->right, key, t->right, b);
            a = t;
        } else {
            split(t->left, key, a, t->left);
            b = t;
        }
        update(a);
        update(b);
    }

    int indexOf(Node *n, int key) const {
        if (!n)
            return 0;
        else if (key < n->key)
            return indexOf(n->left, key);
        else if (n->key == key)
            return getSize(n->left);
        else
            return getSize(n->left) + 1 + indexOf(n->right, key);
    }

public:
    void insert(int key) {
        Node *a, *b;
        split(root, key, a, b);
        root = merge(a, merge(new Node(key), b));
    }

    bool contains(int key) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        bool res = b;
        root = merge(a, merge(b, c));
        return res;
    }

    int indexOf(int key) const {
        return indexOf(root, key);
    }
};

minstd_rand Treap::gen;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int opCount;
    cin >> opCount;

    Treap treap;

    for (int i = 0; i < opCount; i++) {
        int opType, value;
        cin >> opType >> value;

        if (opType == 1)
            treap.insert(value);
        else if (treap.contains(value))
            cout << treap.indexOf(value) + 1 << "\n";
        else
            cout << "Data tidak ada\n";
    }
}