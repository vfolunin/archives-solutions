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
    vector<int> resultArray(vector<int> &a) {
        Treap lTreap, rTreap;
        vector<int> l = { a[0] };
        lTreap.insert(a[0]);
        vector<int> r = { a[1] };
        rTreap.insert(a[1]);

        for (int i = 2; i < a.size(); i++) {
            int lCount = lTreap.greaterCount(a[i]);
            int rCount = rTreap.greaterCount(a[i]);
            if (lCount > rCount || lCount == rCount && l.size() <= r.size()) {
                l.push_back(a[i]);
                lTreap.insert(a[i]);
            } else {
                r.push_back(a[i]);
                rTreap.insert(a[i]);
            }
        }

        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
};