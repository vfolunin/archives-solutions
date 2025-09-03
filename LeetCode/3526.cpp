class ImplicitTreap {
    inline static minstd_rand gen;

    struct Node {
        int value, priority, xorSum, size = 1, rev = 0;
        Node *left = 0, *right = 0;
        Node(int value) : value(value), priority(gen()), xorSum(value) {}
    } *root = 0;

    int getSize(Node *n) {
        return n ? n->size : 0;
    }

    int getXorSum(Node *n) {
        return n ? n->xorSum : 0;
    }

    void push(Node *n) {
        if (n && n->rev) {
            swap(n->left, n->right);
            if (n->left)
                n->left->rev ^= 1;
            if (n->right)
                n->right->rev ^= 1;
            n->rev = 0;
        }
    }

    void update(Node *n) {
        if (n) {
            n->size = getSize(n->left) + 1 + getSize(n->right);
            n->xorSum = getXorSum(n->left) ^ n->value ^ getXorSum(n->right);
        }
    }

    Node *merge(Node *a, Node *b) {
        push(a);
        push(b);
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

    void split(Node *t, int k, Node *&a, Node *&b) {
        push(t);
        if (!t) {
            a = b = 0;
            return;
        }
        if (getSize(t->left) < k) {
            split(t->right, k - getSize(t->left) - 1, t->right, b);
            a = t;
        } else {
            split(t->left, k, a, t->left);
            b = t;
        }
        update(a);
        update(b);
    }

public:
    void pushBack(int value) {
        root = merge(root, new Node(value));
    }

    void set(int index, int value) {
        Node *a, *b, *c;
        split(root, index, a, b);
        split(b, 1, b, c);
        b->value = b->xorSum = value;
        root = merge(a, merge(b, c));
    }

    int getXorSum(int lIndex, int rIndex) {
        Node *a, *b, *c;
        split(root, lIndex, a, b);
        split(b, rIndex - lIndex + 1, b, c);
        int res = getXorSum(b);
        root = merge(a, merge(b, c));
        return res;
    }

    void reverse(int lIndex, int rIndex) {
        Node *a, *b, *c;
        split(root, lIndex, a, b);
        split(b, rIndex - lIndex + 1, b, c);
        b->rev = 1;
        root = merge(a, merge(b, c));
    }
};

class Solution {
public:
    vector<int> getResults(vector<int> &a, vector<vector<int>> &queries) {
        ImplicitTreap treap;
        for (int value : a)
            treap.pushBack(value);
        
        vector<int> res;
        for (vector<int> &query : queries) {
            if (query[0] == 1)
                treap.set(query[1], query[2]);
            else if (query[0] == 2)
                res.push_back(treap.getXorSum(query[1], query[2]));
            else
                treap.reverse(query[1], query[2]);
        }
        return res;
    }
};