class Treap {
    inline static minstd_rand gen;
    
    struct Node {
        int key, priority, size = 1;
        Node *left = 0, *right = 0;
        Node(int key) : key(key), priority(gen()) {}
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
    
    int lessEqualCount(int key) {
        Node *a, *b;
        split(root, key + 1, a, b);
        int res = getSize(a);
        root = merge(a, b);
        return res;
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int> &a, vector<int> &b, int diff) {
        Treap treap;
        long long res = 0;
        
        for (int i = 0; i < a.size(); i++) {
            int value = a[i] - b[i];
            res += treap.lessEqualCount(value + diff);
            treap.insert(value);
        }
        
        return res;
    }
};