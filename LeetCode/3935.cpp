class Treap {
    inline static minstd_rand generator;

    struct Node {
        int key, priority, size = 1;
        Node *left = 0, *right = 0;
        Node(int key) : key(key), priority(generator()) {}
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

    int getByIndex(Node *n, int index) {
        int leftSize = getSize(n->left);
        if (leftSize > index)
            return getByIndex(n->left, index);
        else if (leftSize == index)
            return n->key;
        else
            return getByIndex(n->right, index - leftSize - 1);
    }

public:
    int size() {
        return getSize(root);
    }

    int operator[](int index) {
        return getByIndex(root, index);
    }

    void insert(int key) {
        Node *a, *b;
        split(root, key, a, b);
        root = merge(a, merge(new Node(key), b));
    }
};

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1 % mod;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

class Solution {
public:
    vector<int> powerUpdate(vector<int> &a, int p, vector<vector<int>> &queries) {
        Treap treap;
        for (int value : a)
            treap.insert(value);
        
        const long long MOD = 1e9 + 7;
        vector<int> res;
        for (vector<int> &query : queries) {
            treap.insert(query[0]);
            p = binPow(p, treap[treap.size() - query[1]], MOD);
            res.push_back(p);
        }
        return res;
    }
};