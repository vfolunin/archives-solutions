class Treap {
    inline static minstd_rand gen;
    
    struct Node {
        long long key;
        int priority, size = 1;
        Node *left = 0, *right = 0;
        Node(long long key) : key(key), priority(gen()) {}
    } *root = 0;
    
    int getSize(Node *n) {
        return n ? n->size : 0;
    }
    
    void update(Node *n) {
        if (n)
            n->size = getSize(n->left) + 1 + getSize(n->right);
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
    void insert(long long key) {
        Node *a, *b;
        split(root, key, a, b);
        root = merge(a, merge(new Node(key), b));
    }
    
    int rangeCount(long long l, long long r) {
        Node *a, *b, *c;
        split(root, l, a, b);
        split(b, r + 1, b, c);
        int res = getSize(b);
        root = merge(a, merge(b, c));
        return res;
    }
};

class Solution {
public:
    int countRangeSum(vector<int> &a, int l, int r) {
        long long sum = 0, res = 0;
        
        Treap treap;
        treap.insert(sum);
        
        for (int value : a) {
            sum += value;
            res += treap.rangeCount(sum - r, sum - l);
            treap.insert(sum);
        }
        
        return res;
    }
};