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
        int value, priority, size = 1;
        long long sumOfSquares;
        Node *l = 0, *r = 0;
        Node(int V) : value(V), priority(rand()), sumOfSquares(1LL * value * value) {}
    } *root;


    int getSize(Node *n) {
        return n ? n->size : 0;
    }

    long long getSumOfSquares(Node *n) {
        return n ? n->sumOfSquares : 0;
    }

    void update(Node *n) {
        if (!n)
            return;
        n->size = 1 + getSize(n->l) + getSize(n->r);
        n->sumOfSquares = 1LL * n->value * n->value + getSumOfSquares(n->l) + getSumOfSquares(n->r);
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

    void removeL() {
        Node *a, *b, *c;
        split(root, 1, a, b);
        split(b, 1, b, c);
        int value = a->value;
        b = new Node(b->value + value);
        root = merge(b, c);
    }

    void removeM(int index) {
        Node *a, *b, *c, *d, *e;
        split(root, index - 1, a, b);
        split(b, 1, b, c);
        split(c, 1, c, d);
        split(d, 1, d, e);
        int value = c->value;
        b = new Node(b->value + value / 2);
        d = new Node(d->value + value - value / 2);
        root = merge(merge(a, b), merge(d, e));
    }

    void removeR() {
        Node *a, *b, *c;
        split(root, getSize(root) - 2, a, b);
        split(b, 1, b, c);
        int value = c->value;
        b = new Node(b->value + value);
        root = merge(a, b);
    }

public:
    ImplicitTreap() : root(0) {}

    void pushBack(int value) {
        root = merge(root, new Node(value));
    }

    void add(int index) {
        Node *a, *b, *c;
        split(root, index, a, b);
        split(b, 1, b, c);
        int value = b->value;
        Node *b1 = new Node(value / 2);
        Node *b2 = new Node(value - value / 2);
        root = merge(merge(a, b1), merge(b2, c));
    }

    void remove(int index) {
        if (!index)
            removeL();
        else if (index < getSize(root) - 1)
            removeM(index);
        else
            removeR();
    }

    long long getSumOfSquares() {
        return getSumOfSquares(root);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, subtask;
    cin >> size >> subtask;

    ImplicitTreap implicitTreap;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        implicitTreap.pushBack(value);
    }

    cout << implicitTreap.getSumOfSquares() << "\n";

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int type, index;
        cin >> type >> index;

        if (type == 1)
            implicitTreap.remove(index - 1);
        else
            implicitTreap.add(index - 1);

        cout << implicitTreap.getSumOfSquares() << "\n";
    }
}