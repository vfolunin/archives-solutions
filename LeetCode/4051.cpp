class Treap {
    inline static minstd_rand generator;

    struct Node {
        long long key;
        int priority, size = 1;
        Node *left = 0, *right = 0;
        Node(long long key) : key(key), priority(generator()) {}
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

    int equalCount(long long key) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        int res = getSize(b);
        b = merge(b, c);
        root = merge(a, b);
        return res;
    }

    int lessEqualCount(long long key) {
        Node *a, *b;
        split(root, key + 1, a, b);
        int res = getSize(a);
        root = merge(a, b);
        return res;
    }

    int greaterEqualCount(long long key) {
        Node *a, *b;
        split(root, key, a, b);
        int res = getSize(b);
        root = merge(a, b);
        return res;
    }
};

class Solution {
public:
    long long distantSubarrays(vector<int> &a, int targetSum, int threshold) {
        Treap treap;
        long long sum = 0;
        treap.insert(sum);

        long long res = 0;
        for (int value : a) {
            sum += value;
            res += treap.lessEqualCount(sum - targetSum - threshold);
            res += treap.greaterEqualCount(sum - targetSum + threshold);
            if (!threshold)
                res -= treap.equalCount(sum - targetSum);
            treap.insert(sum);
        }
        return res;
    }
};