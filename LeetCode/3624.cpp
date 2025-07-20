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

    void erase(int key) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        root = merge(a, c);
    }

    int getSize(int lKey, int rKey) {
        Node *a, *b, *c;
        split(root, lKey, a, b);
        split(b, rKey + 1, b, c);
        int res = getSize(b);
        root = merge(a, merge(b, c));
        return res;
    }
};

class Solution {
    int ones(long long n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }

    int getDepth(long long n) {
        return n == 1 ? 0 : 1 + getDepth(ones(n));
    }

public:
    vector<int> popcountDepth(vector<long long> &a, vector<vector<long long>> &queries) {
        vector<Treap> pos(6);
        for (int i = 0; i < a.size(); i++)
            pos[getDepth(a[i])].insert(i);
        
        vector<int> res;
        for (vector<long long> &query : queries) {
            if (query[0] == 1) {
                res.push_back(pos[query[3]].getSize(query[1], query[2]));
            } else {
                pos[getDepth(a[query[1]])].erase(query[1]);
                a[query[1]] = query[2];
                pos[getDepth(query[2])].insert(query[1]);
            }
        }
        return res;
    }
};