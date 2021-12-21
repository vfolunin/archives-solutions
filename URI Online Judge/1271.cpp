#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

minstd_rand gen;

class ITreap {
    struct Node {
        int value, priority, size = 1, rev = 0;
        Node *l = 0, *r = 0;
        Node(int value) : value(value), priority(gen()) {}
    } *root = 0;

    int getSize(Node *n) {
        return n ? n->size : 0;
    }

    void push(Node *n) {
        if (n && n->rev) {
            swap(n->l, n->r);
            if (n->l)
                n->l->rev ^= 1;
            if (n->r)
                n->r->rev ^= 1;
            n->rev = 0;
        }
    }

    void update(Node *n) {
        if (n)
            n->size = 1 + getSize(n->l) + getSize(n->r);
    }

    Node *merge(Node *a, Node *b) {
        push(a);
        push(b);
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
        push(t);
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
    void pushBack(int value) {
        root = merge(root, new Node(value));
    }

    void reverse(int l, int r) {
        Node *a, *b, *c;
        split(root, l, a, b);
        split(b, r - l + 1, b, c);
        b->rev = 1;
        root = merge(a, merge(b, c));
    }

    int get(int i) {
        Node *a, *b, *c;
        split(root, i, a, b);
        split(b, 1, b, c);
        int res = b->value;
        root = merge(a, merge(b, c));
        return res;
    }
};

bool solve(int test) {
    int size;
    cin >> size;

    if (!size)
        return 0;

    ITreap t;
    for (int value = 0; value < size; value++)
        t.pushBack(value);

    int reverseCount;
    cin >> reverseCount;

    for (int i = 0; i < reverseCount; i++) {
        int l, r;
        cin >> l >> r;
        t.reverse(l - 1, r - 1);
    }

    vector<int> finalPos(size);
    for (int i = 0; i < size; i++)
        finalPos[t.get(i)] = i;

    int queryCount;
    cin >> queryCount;

    cout << "Genome " << test << "\n";
    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;
        cout << finalPos[value - 1] + 1 << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}