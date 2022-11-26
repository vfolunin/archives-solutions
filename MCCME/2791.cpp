#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

class ImplicitTreap {
    inline static minstd_rand generator;

    struct Node {
        int priority;
        int value, size = 1;
        Node *l = 0, *r = 0;
        Node(int value) : priority(generator()), value(value) {}
    } *root = nullptr;

    static int getSize(Node *n) {
        return n ? n->size : 0;
    }

    static void update(Node *n) {
        if (n)
            n->size = getSize(n->l) + 1 + getSize(n->r);
    }

    static Node *merge(Node *a, Node *b) {
        if (!a || !b)
            return a ? a : b;
        if (a->priority > b->priority) {
            a->r = merge(a->r, b);
            update(a);
            return a;
        } else {
            b->l = merge(a, b->l);
            update(b);
            return b;
        }
    }

    static void split(Node *n, int k, Node *&a, Node *&b) {
        if (!n) {
            a = b = nullptr;
            return;
        }
        if (getSize(n->l) < k) {
            split(n->r, k - getSize(n->l) - 1, n->r, b);
            a = n;
        } else {
            split(n->l, k, a, n->l);
            b = n;
        }
        update(a);
        update(b);
    }

public:
    int get(int index) {
        Node *less, *equal, *greater;
        split(root, index, less, greater);
        split(greater, 1, equal, greater);
        int result = equal->value;
        root = merge(merge(less, equal), greater);
        return result;
    }

    void pushBack(int value) {
        root = merge(root, new Node(value));
    }

    void toFront(int l, int r) {
        Node *less, *equal, *greater;
        split(root, l, less, greater);
        split(greater, r - l + 1, equal, greater);
        root = merge(merge(equal, less), greater);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ImplicitTreap t;

    int size, queryCount;
    cin >> size >> queryCount;

    for (int i = 1; i <= size; i++)
        t.pushBack(i);

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        t.toFront(l - 1, r - 1);
    }

    for (int i = 0; i < size; i++)
        cout << t.get(i) << " ";
}