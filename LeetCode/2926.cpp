class Treap {
    inline static minstd_rand gen;

    struct Node {
        int key, priority;
        long long value, maxValue;
        Node *left = 0, *right = 0;
        Node(int key, long long value) : key(key), priority(gen()), value(value), maxValue(value) {}
    } *root = 0;

    long long getMaxValue(Node *n) {
        return n ? n->maxValue : -1e18;
    }

    void update(Node *n) {
        if (n)
            n->maxValue = max({ getMaxValue(n->left), n->value, getMaxValue(n->right) });
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
    void insert(int key, long long value) {
        Node *a, *b;
        split(root, key, a, b);
        root = merge(a, merge(new Node(key, value), b));
    }

    long long getMaxValue(int lKey, int rKey) {
        Node *a, *b, *c;
        split(root, lKey, a, b);
        split(b, rKey + 1, b, c);
        long long res = getMaxValue(b);
        root = merge(a, merge(b, c));
        return res;
    }
};

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int> &a) {
        Treap treap;
        long long res = -1e18;

        for (int i = 0; i < a.size(); i++) {
            long long cur = a[i] + max(treap.getMaxValue(-2e9, a[i] - i), 0LL);
            res = max(res, cur);
            treap.insert(a[i] - i, cur);
        }

        return res;
    }
};