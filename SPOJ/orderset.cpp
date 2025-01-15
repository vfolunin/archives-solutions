#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class Treap {
    struct Node {
        int key, priority, size = 1;
        Node *left = 0, *right = 0;
        Node(int key) : key(key), priority(rand()) {}
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

    int indexOf(int key) const {
        return indexOf(root, key);
    }

    int operator[](int index) const {
        return getByIndex(root, index);
    }

    void insert(int key) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        if (!b)
            b = new Node(key);
        root = merge(a, merge(b, c));
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
        char type;
        int value;
        cin >> type >> value;

        if (type == 'I') {
            treap.insert(value);
        } else if (type == 'D') {
            treap.erase(value);
        } else if (type == 'K') {
            if (value <= treap.size())
                cout << treap[value - 1] << "\n";
            else
                cout << "invalid\n";
        } else {
            cout << treap.indexOf(value) << "\n";
        }
    }
}