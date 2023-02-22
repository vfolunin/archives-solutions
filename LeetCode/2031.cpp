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

    int lessCount(int key) {
        Node *a, *b;
        split(root, key, a, b);
        int res = getSize(a);
        root = merge(a, b);
        return res;
    }
};

class Solution {
public:
    int subarraysWithMoreZerosThanOnes(vector<int> &a) {
        const long long MOD = 1e9 + 7;

        int sum = 0;
        Treap treap;
        treap.insert(sum);

        long long res = 0;

        for (int value : a) {
            sum += value ? 1 : -1;
            res = (res + treap.lessCount(sum)) % MOD;
            treap.insert(sum);
        }

        return res;
    }
};