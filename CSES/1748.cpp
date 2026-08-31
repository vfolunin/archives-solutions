#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

const int MOD = 1e9 + 7;

class Treap {
    inline static minstd_rand generator;

    struct Node {
        int key, priority, value, valueSum;
        Node *left = 0, *right = 0;
        Node(int key, int value) : key(key), priority(generator()), value(value), valueSum(value) {}
    } *root = 0;

    int getValueSum(Node *n) {
        return n ? n->valueSum : 0;
    }

    void update(Node *n) {
        if (n)
            n->valueSum = ((getValueSum(n->left) + n->value) % MOD + getValueSum(n->right)) % MOD;
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
        Node *less, *equal, *greater;
        split(root, key, less, equal);
        split(equal, key + 1, equal, greater);
        equal = new Node(key, (getValueSum(equal) + value) % MOD);
        root = merge(less, merge(equal, greater));
    }

    int getValueSum(int key) {
        Node *less, *notLess;
        split(root, key, less, notLess);
        int res = getValueSum(less);
        root = merge(less, notLess);
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    Treap treap;
    int res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        int cur = (treap.getValueSum(value) + 1) % MOD;
        treap.insert(value, cur);
        res = (res + cur) % MOD;
    }

    cout << res;
}