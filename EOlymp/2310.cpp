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
        int key, priority;
        long long sum;
        Node *left = 0, *right = 0;
        Node(int key) : key(key), priority(gen()), sum(key) {}
    } *root = 0;

    long long getSum(Node *n) const {
        return n ? n->sum : 0;
    }

    void update(Node *n) {
        if (n)
            n->sum = getSum(n->left) + n->key + getSum(n->right);
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
    void insert(int key) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        if (!b)
            b = new Node(key);
        root = merge(a, merge(b, c));
    }

    long long getSum(int l, int r) {
        Node *a, *b, *c;
        split(root, l, a, b);
        split(b, r + 1, b, c);
        long long res = getSum(b);
        root = merge(a, merge(b, c));
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int opCount;
    cin >> opCount;

    Treap treap;

    long long prev = 0;
    const long long MOD = 1e9;

    for (int i = 0; i < opCount; i++) {
        char type;
        cin >> type;

        if (type == '+') {
            int key;
            cin >> key;

            treap.insert((key + prev) % MOD);
            prev = 0;
        } else {
            int l, r;
            cin >> l >> r;

            prev = treap.getSum(l, r);
            cout << prev << "\n";
        }
    }
}