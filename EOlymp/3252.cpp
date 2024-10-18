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
        int key, priority, value;
        long long sum;
        Node *left = 0, *right = 0;
        Node(int key, int value) : key(key), priority(gen()), value(value), sum(value) {}
    } *root = 0;

    long long getSum(Node *n) const {
        return n ? n->sum : 0;
    }

    void update(Node *n) {
        if (n)
            n->sum = getSum(n->left) + n->value + getSum(n->right);
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
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        root = merge(a, merge(new Node(key, value), c));
    }

    long long getSum(int lKey, int rKey) {
        Node *a, *b, *c;
        split(root, lKey, a, b);
        split(b, rKey + 1, b, c);
        long long res = getSum(b);
        root = merge(a, merge(b, c));
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, opCount;
    cin >> size >> opCount;

    Treap treap;
    long long p = 91, q = 47;
    const long long MOD = 1e9 + 7;

    for (int i = 0; i < opCount; i++) {
        char op;
        cin >> op;

        if (op == '?') {
            int l, r;
            cin >> l >> r;

            l = (l + p) % size;
            r = (r + q) % size;
            if (l > r)
                swap(l, r);

            long long res = treap.getSum(l, r);
            p = (p * 31 + res) % MOD;
            q = (q * 29 + res) % MOD;

            cout << res << "\n";
        } else {
            int index, value;
            cin >> index >> value;

            index = (index + p) % size;
            value = (value + q) % MOD;

            treap.insert(index, value);
        }
    }
}