class Treap {
    inline static minstd_rand gen;

    struct Node {
        int key, priority, maxValue;
        multiset<int> values;
        Node *left = 0, *right = 0;
        Node(int key, int value) : key(key), priority(gen()), maxValue(value), values({ value }) {}
    } *root = 0;

    int getMaxValue(Node *n) {
        return n ? n->maxValue : -1e9;
    }

    void update(Node *n) {
        if (n)
            n->maxValue = max({ getMaxValue(n->left), *prev(n->values.end()), getMaxValue(n->right) });
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
    void insert(int key, int value) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        if (!b)
            b = new Node(key, value);
        else
            b->values.insert(value);
        update(b);
        root = merge(a, merge(b, c));
    }

    void erase(int key, int value) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        if (b->values.size() > 1)
            b->values.erase(b->values.find(value));
        else
            b = 0;
        update(b);
        root = merge(a, merge(b, c));
    }

    int getMaxValue(int lKey, int rKey) {
        Node *a, *b, *c;
        split(root, lKey, a, b);
        split(b, rKey + 1, b, c);
        int res = getMaxValue(b);
        root = merge(a, merge(b, c));
        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int> &price, vector<int> &profit) {
        Treap l, r;
        for (int i = 0; i < price.size(); i++)
            r.insert(price[i], profit[i]);
        
        int res = -1;
        for (int i = 0; i < price.size(); i++) {
            r.erase(price[i], profit[i]);
            res = max(res, l.getMaxValue(-1e9, price[i] - 1) + profit[i] + r.getMaxValue(price[i] + 1, 1e9));
            l.insert(price[i], profit[i]);
        }
        return res;
    }
};