#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

struct ImplicitTreap {
    inline static minstd_rand gen;

    struct Node {
        int value, priority, size = 1;
        long long sum;
        Node *left = 0, *right = 0;
        Node(int value) : value(value), priority(gen()), sum(value) {}
    } *root = 0;

    int getSize(Node *n) {
        return n ? n->size : 0;
    }

    long long getSum(Node *n) {
        return n ? n->sum : 0;
    }

    void update(Node *n) {
        if (n) {
            n->size = getSize(n->left) + 1 + getSize(n->right);
            n->sum = getSum(n->left) + n->value + getSum(n->right);
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

    void split(Node *t, int k, Node *&a, Node *&b) {
        if (!t) {
            a = b = 0;
            return;
        }
        if (getSize(t->left) < k) {
            split(t->right, k - getSize(t->left) - 1, t->right, b);
            a = t;
        } else {
            split(t->left, k, a, t->left);
            b = t;
        }
        update(a);
        update(b);
    }

    vector<Node *> split(int lIndex, int rIndex) {
        Node *a, *b, *c;
        split(root, lIndex, a, b);
        split(b, rIndex - lIndex + 1, b, c);
        return { a, b, c };
    }

    void pushBack(int value) {
        root = merge(root, new Node(value));
    }

    int getSize() {
        return getSize(root);
    }

    long long getSum(int lIndex, int rIndex) {
        Node *a, *b, *c;
        split(root, lIndex, a, b);
        split(b, rIndex - lIndex + 1, b, c);
        long long res = getSum(b);
        root = merge(a, merge(b, c));
        return res;
    }
};

struct Swapper {
    ImplicitTreap t0, t1;

    void pushBack(int value) {
        if ((t0.getSize() + t1.getSize()) % 2 == 0)
            t0.pushBack(value);
        else
            t1.pushBack(value);
    }

    void swap(int l, int r) {
        int l0 = l, r0 = r;
        if (l0 % 2)
            l0++;
        if (r0 % 2)
            r0--;
        auto parts0 = t0.split(l0 / 2, r0 / 2);

        int l1 = l, r1 = r;
        if (l1 % 2 == 0)
            l1++;
        if (r1 % 2 == 0)
            r1--;
        auto parts1 = t1.split(l1 / 2, r1 / 2);

        t0.root = t0.merge(parts0[0], t0.merge(parts1[1], parts0[2]));
        t1.root = t1.merge(parts1[0], t1.merge(parts0[1], parts1[2]));
    }

    long long getSum(int l, int r) {
        int l0 = l, r0 = r;
        if (l0 % 2)
            l0++;
        if (r0 % 2)
            r0--;
        long long s0 = l0 <= r0 ? t0.getSum(l0 / 2, r0 / 2) : 0;

        int l1 = l, r1 = r;
        if (l1 % 2 == 0)
            l1++;
        if (r1 % 2 == 0)
            r1--;
        long long s1 = l1 <= r1 ? t1.getSum(l1 / 2, r1 / 2) : 0;

        return s0 + s1;
    }

    int get(int index) {
        if (index % 2 == 0)
            return t0.getSum(index / 2, index / 2);
        else
            return t1.getSum(index / 2, index / 2);
    }
};

bool solve(int test) {
    int size, queryCount;
    cin >> size >> queryCount;

    if (!size && !queryCount)
        return 0;

    Swapper swapper;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        swapper.pushBack(value);
    }

    if (test > 1)
        cout << "\n";
    cout << "Swapper " << test << ":\n";
    for (int i = 0; i < queryCount; i++) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1)
            swapper.swap(l - 1, r - 1);
        else
            cout << swapper.getSum(l - 1, r - 1) << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}