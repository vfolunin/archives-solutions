class Treap {
    inline static minstd_rand gen;

    struct Node {
        long long key;
        int priority, size = 1;
        Node *left = 0, *right = 0;
        Node(long long key) : key(key), priority(gen()) {}
    } *root = 0;

    int getSize(Node *n) const {
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

    void split(Node *t, long long key, Node *&a, Node *&b) {
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
    void insert(long long key) {
        Node *a, *b;
        split(root, key, a, b);
        root = merge(a, merge(new Node(key), b));
    }

    int count(long long lKey, long long rKey) {
        Node *a, *b, *c;
        split(root, lKey, a, b);
        split(b, rKey, b, c);
        int res = getSize(b);
        root = merge(a, merge(b, c));
        return res;
    }
};

class Solution {
    bool can(vector<int> &a, long long limit, int threshold) {
        Treap treap;
        long long count = 0;
        for (int value : a) {
            count += treap.count(value + 1, value + limit + 1);
            treap.insert(value);
        }
        return count >= threshold;
    }

public:
    int minThreshold(vector<int> &a, int threshold) {
        long long l = 0, r = 1e10;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(a, m, threshold))
                r = m;
            else
                l = m;
        }
        return r != 1e10 ? r : -1;
    }
};