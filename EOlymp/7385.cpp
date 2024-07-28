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
        int value, priority, size = 1, add = 0;
        Node *l = 0, *r = 0;
        Node(int value) : value(value), priority(rand()) {}
    } *root;


    int getSize(Node *n) {
        return n ? n->size : 0;
    }

    void push(Node *n) {
        if (n && n->add) {
            n->value += n->add;
            if (n->l)
                n->l->add += n->add;
            if (n->r)
                n->r->add += n->add;
            n->add = 0;
        }
    }

    void update(Node *n) {
        if (!n)
            return;
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

    void splitByValue(Node *t, int val, Node *&a, Node *&b) {
        push(t);
        if (!t) {
            a = b = 0;
            return;
        }
        if (t->value < val) {
            splitByValue(t->r, val, t->r, b);
            a = t;
        } else {
            splitByValue(t->l, val, a, t->l);
            b = t;
        }
        update(a);
        update(b);
    }

    int min(Node *t) {
        if (!t)
            return 1e9;
        push(t);
        return t->l ? min(t->l) : t->value;
    }

    int max(Node *t) {
        if (!t)
            return -1e9;
        push(t);
        return t->r ? max(t->r) : t->value;
    }

public:
    ImplicitTreap() : root(0) {}

    int size() {
        return getSize(root);
    }

    void pushBack(int value) {
        root = merge(root, new Node(value));
    }

    void decrease(int count) {
        Node *l, *r;
        split(root, size() - count, l, r);
        if (r)
            r->add = -1;

        int maxL = max(l), minR = min(r);
        Node *lSwap, *rSwap;
        splitByValue(l, maxL, l, lSwap);
        splitByValue(r, minR + 1, rSwap, r);

        if (maxL > minR)
            swap(lSwap, rSwap);

        root = l;
        if (lSwap && lSwap->value)
            root = merge(root, lSwap);
        if (rSwap && rSwap->value)
            root = merge(root, rSwap);
        root = merge(root, r);
    }
};

void solve() {
    int width, height;
    cin >> width >> height;

    vector<int> cols(width);
    for (int &col : cols)
        cin >> col;

    vector<int> rows(height);
    for (int &row : rows)
        cin >> row;

    ImplicitTreap implicitTreap;

    sort(cols.begin(), cols.end());
    for (int col : cols)
        if (col)
            implicitTreap.pushBack(col);

    sort(rows.rbegin(), rows.rend());
    for (int row : rows) {
        if (row > implicitTreap.size()) {
            cout << "0\n";
            return;
        }
        implicitTreap.decrease(row);
    }

    cout << !implicitTreap.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}