#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class ImplicitTreap {
    struct Node {
        char value;
        int priority, size = 1;
        Node *left = 0, *right = 0;
        Node(char value) : value(value), priority(rand()) {}
    } *root = 0;

    int getSize(Node *n) {
        return n ? n->size : 0;
    }

    void update(Node *n) {
        if (n)
            n->size = getSize(n->left) + 1 + getSize(n->right);
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

    void print(Node *t) {
        if (!t)
            return;
        print(t->left);
        cout << t->value;
        print(t->right);
    }

public:
    void pushBack(char value) {
        root = merge(root, new Node(value));
    }

    void toFront(int l, int r) {
        Node *a, *b, *c;
        split(root, l, a, b);
        split(b, r - l + 1, b, c);
        root = merge(merge(b, a), c);
    }

    void print() {
        print(root);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    string s;
    cin >> size >> queryCount >> s;

    ImplicitTreap implicitTreap;
    for (char c : s)
        implicitTreap.pushBack(c);

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;

        implicitTreap.toFront(l - 1, r - 1);
    }

    implicitTreap.print();
}