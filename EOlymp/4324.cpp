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
        int value, priority, minValue, size = 1, rev = 0;
        Node *left = 0, *right = 0;
        Node(int value) : value(value), priority(gen()), minValue(value) {}
    } *root = 0;

    int getSize(Node *n) {
        return n ? n->size : 0;
    }

    int getMinValue(Node *n) {
        return n ? n->minValue : 2e9;
    }

    void push(Node *n) {
        if (n && n->rev) {
            swap(n->left, n->right);
            if (n->left)
                n->left->rev ^= 1;
            if (n->right)
                n->right->rev ^= 1;
            n->rev = 0;
        }
    }

    void update(Node *n) {
        if (n) {
            n->size = getSize(n->left) + 1 + getSize(n->right);
            n->minValue = min({ getMinValue(n->left), n->value, getMinValue(n->right) });
        }
    }

    Node *merge(Node *a, Node *b) {
        push(a);
        push(b);
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
        push(t);
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
    void pushBack(int value) {
        root = merge(root, new Node(value));
    }

    int getMinValue(int lIndex, int rIndex) {
        Node *a, *b, *c;
        split(root, lIndex, a, b);
        split(b, rIndex - lIndex + 1, b, c);
        int res = getMinValue(b);
        root = merge(a, merge(b, c));
        return res;
    }

    void reverse(int lIndex, int rIndex) {
        Node *a, *b, *c;
        split(root, lIndex, a, b);
        split(b, rIndex - lIndex + 1, b, c);
        b->rev = 1;
        root = merge(a, merge(b, c));
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    ImplicitTreap implicitTreap;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        implicitTreap.pushBack(value);
    }

    for (int i = 0; i < queryCount; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        l--;
        r--;

        if (type == 1)
            implicitTreap.reverse(l, r);
        else
            cout << implicitTreap.getMinValue(l, r) << "\n";
    }
}