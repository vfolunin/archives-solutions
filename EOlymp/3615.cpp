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
        int value, priority, size = 1, minValue;
        Node *left = 0, *right = 0;
        Node(int value) : value(value), priority(gen()), minValue(value) {}
    } *root = 0;

    int getSize(Node *n) {
        return n ? n->size : 0;
    }

    int getMinValue(Node *n) {
        return n ? n->minValue : 2e9;
    }

    void update(Node *n) {
        if (n) {
            n->size = getSize(n->left) + 1 + getSize(n->right);
            n->minValue = min({ getMinValue(n->left), n->value, getMinValue(n->right) });
        }
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
    void insertAfter(int index, int value) {
        Node *a, *b;
        split(root, index, a, b);
        root = merge(a, merge(new Node(value), b));
    }

    int getMinValue(int l, int r) {
        Node *a, *b, *c;
        split(root, l, a, b);
        split(b, r - l + 1, b, c);
        int res = getMinValue(b);
        root = merge(a, merge(b, c));
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int opCount;
    cin >> opCount;

    ImplicitTreap treap;

    for (int i = 0; i < opCount; i++) {
        string op;
        cin >> op;

        if (op == "+") {
            int index, value;
            cin >> index >> value;
            treap.insertAfter(index, value);
        } else {
            int l, r;
            cin >> l >> r;
            cout << treap.getMinValue(l - 1, r - 1) << "\n";
        }
    }
}