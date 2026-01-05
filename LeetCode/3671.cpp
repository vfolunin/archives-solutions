const long long MOD = 1e9 + 7;

class Treap {
    inline static minstd_rand generator;

    struct Node {
        int key, priority, value;
        long long sum = value;
        Node *left = 0, *right = 0;
        Node(int key, int value) : key(key), priority(generator()), value(value), sum(value) {}
    } *root = 0;

    int getSum(Node *n) const {
        return n ? n->sum : 0;
    }

    void update(Node *n) {
        if (n)
            n->sum = (0LL + getSum(n->left) + n->value + getSum(n->right)) % MOD;
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
    void add(int key) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        root = merge(a, merge(new Node(key, getSum(a) + getSum(b) + 1), c));
    }

    long long getSum() {
        return getSum(root);
    }
};

class Solution {
    long long getIncreasingSubsequenceCount(vector<int> &a) {
        Treap treap;
        for (int value : a)
            treap.add(value);
        return treap.getSum();
    }

public:
    int totalBeauty(vector<int> &a) {
        int maxValue = *max_element(a.begin(), a.end());

        vector<vector<int>> gcdA(maxValue + 1);
        for (int value : a) {
            for (int divisor = 1; divisor * divisor <= value; divisor++) {
                if (value % divisor)
                    continue;
                gcdA[divisor].push_back(value);
                if (divisor * divisor != value)
                    gcdA[value / divisor].push_back(value);
            }
        }

        vector<long long> subsequenceCount(gcdA.size());
        for (int divisor = 1; divisor < subsequenceCount.size(); divisor++)
            subsequenceCount[divisor] = getIncreasingSubsequenceCount(gcdA[divisor]);
        for (int divisor = subsequenceCount.size() - 1; divisor; divisor--)
            for (int factor = 2; factor * divisor < subsequenceCount.size(); factor++)
                subsequenceCount[divisor] = (subsequenceCount[divisor] - subsequenceCount[divisor * factor] + MOD) % MOD;

        long long res = 0;
        for (int divisor = 1; divisor < gcdA.size(); divisor++)
            res = (res + divisor * subsequenceCount[divisor]) % MOD;
        return res;
    }
};