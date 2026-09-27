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
    vector<int> countSmallerOppositeParity(vector<int> &a) {
        vector<Treap> treap(2);
        vector<int> res(a.size());
        for (int i = a.size() - 1; i >= 0; i--) {
            res[i] = treap[1 - a[i] % 2].lessCount(a[i]);
            treap[a[i] % 2].insert(a[i]);
        }
        return res;
    }
};