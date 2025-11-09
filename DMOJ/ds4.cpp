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

    int indexOf(Node *n, int key) const {
        if (!n) {
            return -1;
        } else if (key < n->key) {
            return indexOf(n->left, key);
        } else if (n->key == key) {
            int res = indexOf(n->left, key);
            return res != -1 ? res : getSize(n->left);
        } else {
            int res = indexOf(n->right, key);
            return res != -1 ? getSize(n->left) + 1 + res : res;
        }
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

    void print(Node *n) {
        if (!n)
            return;
        print(n->left);
        cout << n->key << " ";
        print(n->right);
    }

public:
    int indexOf(int key) const {
        int res = indexOf(root, key);
        return res != -1 ? res + 1 : res;
    }

    int getByIndex(int index) const {
        if (index < 1 || index > getSize(root))
            return -1;
        return getByIndex(root, index - 1);
    }

    void insert(int key) {
        Node *a, *b;
        split(root, key, a, b);
        root = merge(a, merge(new Node(key), b));
    }

    void eraseOne(int key) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        if (b)
            b = merge(b->left, b->right);
        root = merge(a, merge(b, c));
    }

    void print() {
        print(root);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    Treap treap;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        treap.insert(value);
    }

    int prevRes = 0;
    for (int i = 0; i < queryCount; i++) {
        char type;
        int value;
        cin >> type >> value;
        //value ^= prevRes;

        if (type == 'I')
            treap.insert(value);
        else if (type == 'R')
            treap.eraseOne(value);
        else if (type == 'S')
            cout << (prevRes = treap.getByIndex(value)) << "\n";
        else
            cout << (prevRes = treap.indexOf(value)) << "\n";
    }

    treap.print();
}