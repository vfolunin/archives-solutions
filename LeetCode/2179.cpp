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
    long long goodTriplets(vector<int> &a, vector<int> &b) {
        vector<int> posInB(a.size());
        for (int i = 0; i < a.size(); i++)
            posInB[b[i]] = i;
        
        Treap treap;
        vector<int> l(a.size());
        for (int i = 0; i < a.size(); i++) {
            l[a[i]] = treap.lessCount(posInB[a[i]]);
            treap.insert(posInB[a[i]]);
        }
        
        treap = Treap();
        vector<int> r(a.size());
        for (int i = a.size() - 1; i >= 0; i--) {
            r[a[i]] = treap.greaterCount(posInB[a[i]]);
            treap.insert(posInB[a[i]]);
        }
        
        long long res = 0;
        for (int i = 0; i < a.size(); i++)
            res += 1LL * l[i] * r[i];
        return res;
    }
};