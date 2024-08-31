#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

class Treap {
    inline static minstd_rand gen;

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

    int getByIndex(Node *n, int index) const {
        int leftSize = getSize(n->left);
        if (leftSize > index)
            return getByIndex(n->left, index);
        else if (leftSize == index)
            return n->key;
        else
            return getByIndex(n->right, index - leftSize - 1);
    }

public:
    int size() const {
        return getSize(root);
    }

    int operator[](int index) const {
        return getByIndex(root, index);
    }

    void insert(int key) {
        Node *a, *b;
        split(root, key, a, b);
        root = merge(a, merge(new Node(key), b));
    }

    void erase(int key) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        root = merge(a, c);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    Treap treap;

    for (int i = 0; i < queryCount; i++) {
        int type, value;
        cin >> type >> value;

        if (type == 1)
            treap.insert(value);
        else if (type == -1)
            treap.erase(value);
        else
            cout << treap[treap.size() - value] << "\n";
    }
}