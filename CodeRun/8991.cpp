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

    void pushBack(int value) {
        root = merge(root, new Node(value));
    }

    void popFront() {
        Node *a, *b;
        split(root, 1, a, b);
        root = b;
    }

    long long getSumTo(int index) {
        Node *a, *b;
        split(root, index, a, b);
        long long res = getSum(a);
        root = merge(a, b);
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, threshold;
    cin >> size >> threshold;

    ImplicitTreap implicitTreap;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        implicitTreap.pushBack(value >= threshold);
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int value;
            cin >> value;

            implicitTreap.pushBack(value >= threshold);
        } else if (type == 2) {
            implicitTreap.popFront();
        } else {
            int index;
            cin >> index;

            cout << implicitTreap.getSumTo(index) << "\n";
        }
    }
}