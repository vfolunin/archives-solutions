class Treap {
    inline static minstd_rand gen;

    struct Node {
        int key, priority, size = 1;
        Node *left = 0, *right = 0;
        Node(int key) : key(key), priority(gen()) {}
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
        Node *a, *b;
        split(root, key, a, b);
        root = merge(a, merge(new Node(key), b));
    }

    void eraseOne(int key) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        if (b)
            b = merge(b->left, b->right);
        root = merge(a, merge(b, c));
    }

    int lessCount(int key) {
        Node *a, *b;
        split(root, key, a, b);
        int res = getSize(a);
        root = merge(a, b);
        return res;
    }

    int greaterCount(int key) {
        Node *a, *b;
        split(root, key + 1, a, b);
        int res = getSize(b);
        root = merge(a, b);
        return res;
    }
};

class Solution {
public:
    long long minInversionCount(vector<int> &a, int width) {
        Treap treap;
        long long cur = 0;
        for (int i = 0; i < width; i++) {
            cur += treap.greaterCount(a[i]);
            treap.insert(a[i]);
        }

        long long res = cur;
        for (int i = width; i < a.size(); i++) {
            cur -= treap.lessCount(a[i - width]);
            treap.eraseOne(a[i - width]);
            cur += treap.greaterCount(a[i]);
            treap.insert(a[i]);
            res = min(res, cur);
        }
        return res;
    }
};