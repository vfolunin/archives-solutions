#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

class ImplicitTreap {
    static minstd_rand generator;

    struct Node {
        int value, priority, size = 1, id, maxValue;
        Node *l = 0, *r = 0;
        Node(int id, int value) : id(id), value(value), priority(rand()), maxValue(value) {}
    } *root;

    int getSize(Node *n) {
        return n ? n->size : 0;
    }

    int getMaxValue(Node *n) {
        return n ? n->maxValue : -2e9;
    }

    void update(Node *n) {
        if (!n)
            return;
        n->size = 1 + getSize(n->l) + getSize(n->r);
        n->maxValue = max(n->value, max(getMaxValue(n->l), getMaxValue(n->r)));
    }

    Node *merge(Node *a, Node *b) {
        if (!a || !b)
            return a ? a : b;
        if (a->priority > b->priority) {
            a->r = merge(a->r, b);
            update(a);
            return a;
        } else {
            b->l = merge(a, b->l);
            update(b);
            return b;
        }
    }

    void split(Node *t, int k, Node *&a, Node *&b) {
        if (!t) {
            a = b = 0;
            return;
        }
        if (getSize(t->l) < k) {
            split(t->r, k - getSize(t->l) - 1, t->r, b);
            a = t;
        } else {
            split(t->l, k, a, t->l);
            b = t;
        }
        update(a);
        update(b);
    }

public:
    ImplicitTreap() : root(0) {}

    int getMaxValue(int l) {
        Node *a, *b;
        split(root, l, a, b);
        int res = getMaxValue(b);
        root = merge(a, b);
        return res;
    }

    void add(int id, int value, int partSize) {
        int l = max(0, getSize(root) - partSize), r = getSize(root);
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (getMaxValue(m) > value)
                l = m;
            else
                r = m;
        }
        int index = getMaxValue(l) <= value ? l : r;
        Node *a, *b;
        split(root, index, a, b);
        root = merge(a, merge(new Node(id, value), b));
    }

    int operator[](int index) {
        Node *a, *b, *c;
        split(root, index, a, b);
        split(b, 1, b, c);
        int res = b->id;
        root = merge(a, merge(b, c));
        return res;
    }

    void printIds() {
        for (int i = 0; i < getSize(root); i++)
            cout << (*this)[i] << " ";
        cout << "\n";
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    ImplicitTreap implicitTreap;
    for (int i = 0; i < size; i++) {
        int value, partSize;
        cin >> value >> partSize;
        implicitTreap.add(i + 1, value, partSize);
    }

    implicitTreap.printIds();
}