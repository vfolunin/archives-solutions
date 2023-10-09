class Treap {
    inline static minstd_rand gen;

    struct Node {
        int key, priority, value, minValue;
        Node *left = 0, *right = 0;
        Node(int key, int value) : key(key), priority(gen()), value(value), minValue(value) {}
    } *root = 0;

    int getMinValue(Node *n) const {
        return n ? n->minValue : 2e9;
    }

    void update(Node *n) {
        if (n)
            n->minValue = min({ getMinValue(n->left), n->value, getMinValue(n->right) });
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

    int getMinValue(int key) {
        Node *a, *b;
        split(root, key, a, b);
        int res = getMinValue(b);
        root = merge(a, b);
        return res;
    }
};

class Solution {
public:
    int maxSubarrayLength(vector<int> &a) {
        Treap treap;
        int res = 0;

        for (int i = 0; i < a.size(); i++) {
            res = max(res, i - treap.getMinValue(a[i] + 1) + 1);
            treap.insert(a[i], i);
        }

        return res;
    }
};