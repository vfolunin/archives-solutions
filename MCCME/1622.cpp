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
        int key, priority, value, maxValue, setValue = -1;
        Node *left = 0, *right = 0;
        Node(int key, int value) : key(key), priority(gen()), value(value), maxValue(value) {}
    } *root = 0;

    int getMaxValue(Node *n) {
        if (!n)
            return -2e9;
        if (n->setValue != -1)
            return n->setValue;
        return n->maxValue;
    }

    void push(Node *n) {
        if (n && n->setValue != -1) {
            n->value = n->maxValue = n->setValue;
            if (n->left)
                n->left->setValue = n->setValue;
            if (n->right)
                n->right->setValue = n->setValue;
            n->setValue = -1;
        }
    }

    void update(Node *n) {
        if (n)
            n->maxValue = max({ getMaxValue(n->left), n->value, getMaxValue(n->right) });
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

    void split(Node *t, int key, Node *&a, Node *&b) {
        push(t);
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

public:
    void insert(int key, int value) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        root = merge(a, merge(new Node(key, value), c));
    }

    void setValue(int lKey, int rKey, int value) {
        Node *a, *b, *c;
        split(root, lKey, a, b);
        split(b, rKey + 1, b, c);
        b->setValue = value;
        root = merge(a, merge(b, c));
    }

    int getMaxValue(int lKey, int rKey) {
        Node *a, *b, *c;
        split(root, lKey, a, b);
        split(b, rKey + 1, b, c);
        int res = getMaxValue(b);
        root = merge(a, merge(b, c));
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int segmentCount;
    cin >> segmentCount >> segmentCount;

    vector<int> l(segmentCount), r(segmentCount);
    Treap treap;
    for (int i = 0; i < segmentCount; i++) {
        cin >> l[i] >> r[i];
        treap.insert(l[i], i);
        treap.insert(r[i], i);
        treap.setValue(l[i], r[i], i);
    }

    int res = 0;
    for (int i = 0; i < segmentCount; i++)
        res += treap.getMaxValue(l[i], r[i]) == i;

    cout << res;
}