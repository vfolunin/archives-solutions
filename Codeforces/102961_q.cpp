#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

class ImplicitTreap {
    inline static minstd_rand gen;

    struct Node {
        int value, priority, size = 1;
        Node *left = 0, *right = 0;
        Node(int value) : value(value), priority(gen()) {}
    } *root = 0;

    int getSize(Node *n) {
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

    void split(Node *t, int k, Node *&a, Node *&b) {
        if (!t) {
            a = b = 0;
            return;
        }
        if (getSize(t->left) < k) {
            split(t->right, k - getSize(t->left) - 1, t->right, b);
            a = t;
        } else {
            split(t->left, k, a, t->left);
            b = t;
        }
        update(a);
        update(b);
    }

public:
    int size() {
        return getSize(root);
    }

    void pushBack(int value) {
        root = merge(root, new Node(value));
    }

    void erase(int index) {
        Node *a, *b, *c;
        split(root, index, a, b);
        split(b, 1, b, c);
        root = merge(a, c);
    }

    int operator[](int index) {
        Node *a, *b, *c;
        split(root, index, a, b);
        split(b, 1, b, c);
        int res = b->value;
        root = merge(a, merge(b, c));
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, step;
    cin >> size >> step;
    step++;

    ImplicitTreap treap;
    for (int value = 1; value <= size; value++)
        treap.pushBack(value);

    int pos = 0;
    while (treap.size()) {
        pos = (pos + step - 1) % treap.size();
        cout << treap[pos] << " ";
        treap.erase(pos);
    }
}