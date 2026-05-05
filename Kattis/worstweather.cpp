#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

class Treap {
    inline static minstd_rand generator;

    struct Node {
        int key, priority, value, size = 1, maxValue;
        Node *left = 0, *right = 0;
        Node(int key, int value) : key(key), priority(generator()), value(value), maxValue(value) {}
    } *root = 0;

    int getSize(Node *n) {
        return n ? n->size : 0;
    }

    int getMaxValue(Node *n) {
        return n ? n->maxValue : -2e9;
    }

    void update(Node *n) {
        if (n) {
            n->size = getSize(n->left) + 1 + getSize(n->right);
            n->maxValue = max({ getMaxValue(n->left), n->value, getMaxValue(n->right) });
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

public:
    void insert(int key, int value) {
        Node *a, *b;
        split(root, key, a, b);
        root = merge(a, merge(new Node(key, value), b));
    }

    pair<int, int> query(int lKey, int rKey) {
        Node *a, *b, *c;
        split(root, lKey, a, b);
        split(b, rKey + 1, b, c);
        pair<int, int> res = { getSize(b), getMaxValue(b) };
        root = merge(a, merge(b, c));
        return res;
    }
};

bool solve() {
    int size;
    cin >> size;

    Treap treap;
    for (int i = 0; i < size; i++) {
        int key, value;
        cin >> key >> value;

        treap.insert(key, value);
    }

    int queryCount;
    cin >> queryCount;

    if (!size && !queryCount)
        return 0;

    for (int i = 0; i < queryCount; i++) {
        int lKey, rKey;
        cin >> lKey >> rKey;

        auto [hasLValue, lValue] = treap.query(lKey, lKey);
        auto [size, maxValue] = treap.query(lKey + 1, rKey - 1);
        auto [hasRValue, rValue] = treap.query(rKey, rKey);

        if (hasLValue && size == rKey - lKey - 1 && hasRValue && lValue >= rValue && maxValue < rValue)
            cout << "true\n";
        else if (hasLValue && hasRValue && lValue < rValue || hasLValue && lValue <= maxValue || hasRValue && rValue <= maxValue)
            cout << "false\n";
        else
            cout << "maybe\n";
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}