#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

const int MOD = 1000007;

class Treap {
    inline static minstd_rand gen;

    struct Node {
        int key, value, sum, priority;
        Node *left = 0, *right = 0;
        Node(int key, int value) : key(key), value((value % MOD + MOD) % MOD), sum((value %MOD + MOD) % MOD), priority(gen()) {}
    } *root = 0;

    int getSum(Node *n) const {
        return n ? n->sum : 0;
    }

    void update(Node *n) {
        if (n)
            n->sum = (getSum(n->left) + n->value + getSum(n->right)) % MOD;
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
        if (b) {
            b->value = (b->value + value) % MOD;
            update(b);
        } else {
            b = new Node(key, value);
        }
        root = merge(a, merge(b, c));
    }

    int getSum(int l, int r) {
        Node *a, *b, *c;
        split(root, l, a, b);
        split(b, r + 1, b, c);
        int res = getSum(b);
        root = merge(a, merge(b, c));
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    Treap treap;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        int count = treap.getSum(-1e9, value - 1);
        treap.insert(value, count + 1);
    }

    cout << treap.getSum(-1e9, 1e9);
}