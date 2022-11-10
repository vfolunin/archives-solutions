class Treap {
    inline static minstd_rand gen;
    
    struct Node {
        long long key;
        int priority, value, maxValue;
        Node *left = 0, *right = 0;
        Node(long long key, int value) : key(key), priority(gen()), value(value), maxValue(value) {}
    } *root = 0;
    
    int getMaxValue(Node *n) {
        return n ? n->maxValue : -1e9;
    }
    
    void update(Node *n) {
        if (n)
            n->maxValue = max({ getMaxValue(n->left), n->value, getMaxValue(n->right) });
    }
    
    Node *merge(Node *a, Node *b) {
        if (!a || !b) {
            return a ? a : b;
        }
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
    void insert(long long key, int value) {
        Node *a, *b;
        split(root, key, a, b);
        root = merge(a, merge(new Node(key, value), b));
    }
    
    int getMaxValue(long long to) {
        Node *a, *b;
        split(root, to + 1, a, b);
        int res = getMaxValue(a);
        root = merge(a, b);
        return res;
    }
};

class Solution {
public:
    int shortestSubarray(vector<int> &a, int k) {
        long long sum = 0;
        Treap treap;
        treap.insert(sum, -1);
        int res = 1e9;
        
        for (int i = 0; i < a.size(); i++) {
            sum += a[i];
            res = min(res, i - treap.getMaxValue(sum - k));
            treap.insert(sum, i);
        }
        
        return res != 1e9 ? res : -1;
    }
};