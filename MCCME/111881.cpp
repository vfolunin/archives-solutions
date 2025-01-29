#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

class ImplicitTreap {
    inline static minstd_rand gen;

    struct Node {
        char value;
        int priority, size = 1;
        Node *left = 0, *right = 0;
        Node(char value) : value(value), priority(gen()) {}
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

public:
    void pushBack(char value) {
        root = merge(root, new Node(value));
    }

    char operator[](int index) {
        Node *a, *b, *c;
        split(root, index, a, b);
        split(b, 1, b, c);
        char res = b->value;
        root = merge(a, merge(b, c));
        return res;
    }

    void move(int from, int to) {
        if (from == to)
            return;

        Node *a, *b, *c, *d;
        if (from < to) {
            split(root, from, a, b);
            split(b, 1, b, c);
            split(c, to - from, c, d);
        } else {
            split(root, from, b, c);
            split(c, 1, c, d);
            split(b, to, a, b);
        }

        root = merge(merge(a, c), merge(b, d));
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
        char type;
        cin >> type;

        if (type == 'a') {
            int from, to;
            cin >> from >> to;

            implicitTreap.move(from - 1, to - 1);
        } else {
            int index;
            cin >> index;

            cout << implicitTreap[index - 1] << "\n";
        }
    }
}