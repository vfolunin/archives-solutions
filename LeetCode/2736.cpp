class Treap {
    inline static minstd_rand gen;

    struct Node {
        int key, priority, value, maxValue;
        Node *left = 0, *right = 0;
        Node(int key, int value) : key(key), priority(gen()), value(value), maxValue(value) {}
    } *root = 0;

    int getMaxValue(Node *n) const {
        return n ? n->maxValue : -2e9;
    }

    void update(Node *n) {
        if (n)
            n->maxValue = max({ getMaxValue(n->left), n->value, getMaxValue(n->right) });
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
        Node *a, *b;
        split(root, key, a, b);
        root = merge(a, merge(new Node(key, value), b));
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
    vector<int> maximumSumQueries(vector<int> &x, vector<int> &y, vector<vector<int>> &queries) {
        vector<int> pointOrder(x.size());
        iota(pointOrder.begin(), pointOrder.end(), 0);
        sort(pointOrder.begin(), pointOrder.end(), [&](int i, int j) {
            return x[i] > x[j];
        });

        vector<int> queryOrder(queries.size());
        iota(queryOrder.begin(), queryOrder.end(), 0);
        sort(queryOrder.begin(), queryOrder.end(), [&](int i, int j) {
            return queries[i][0] > queries[j][0];
        });

        Treap treap;
        vector<int> res(queries.size());

        for (int qi = 0, pi = 0; qi < queryOrder.size(); qi++) {
            while (pi < pointOrder.size() && x[pointOrder[pi]] >= queries[queryOrder[qi]][0]) {
                treap.insert(y[pointOrder[pi]], x[pointOrder[pi]] + y[pointOrder[pi]]);
                pi++;
            }
            res[queryOrder[qi]] = max(treap.getMaxValue(queries[queryOrder[qi]][1], 2e9), -1);
        }

        return res;
    }
};