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

    int indexOf(Node *n, int key) const {
        if (!n)
            return 0;
        else if (key < n->key)
            return indexOf(n->left, key);
        else if (n->key == key)
            return getSize(n->left);
        else
            return getSize(n->left) + 1 + indexOf(n->right, key);
    }

    int getByIndex(Node *n, int index) const {
        int leftSize = getSize(n->left);
        if (leftSize > index)
            return getByIndex(n->left, index);
        else if (leftSize == index)
            return n->key;
        else
            return getByIndex(n->right, index - leftSize - 1);
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
    int getPermutationIndex(vector<int> &a) {
        const long long MOD = 1e9 + 7;
        vector<long long> factorial(a.size(), 1);
        for (int i = 2; i < factorial.size(); i++)
            factorial[i] = factorial[i - 1] * i % MOD;
        
        Treap used;
        long long res = 0;
        for (int i = 0; i < a.size(); i++) {
            res = (res + (a[i] - used.lessCount(a[i]) - 1) * factorial[a.size() - 1 - i] % MOD) % MOD;
            used.insert(a[i]);
        }
        return res;
    }
};