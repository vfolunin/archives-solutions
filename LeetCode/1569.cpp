const long long MOD = 1e9 + 7;

long long c(int n, int m) {
    static vector<vector<long long>> memo(1001, vector<long long>(1001, -1));
    long long &res = memo[n][m];
    if (res != -1)
        return res;

    if (n < m)
        return res = 0;
    if (!n || !m)
        return res = 1;

    return res = (c(n - 1, m) + c(n - 1, m - 1)) % MOD;
}

struct BST {
    struct Node {
        int key, size;
        Node *l = 0, *r = 0;
        Node(int key) : key(key) {}
    } *root = 0;

    void insert(Node *&n, int key) {
        if (!n) {
            n = new Node(key);
            return;
        }
        if (key < n->key)
            insert(n->l, key);
        else
            insert(n->r, key);
    }

    int size(Node *n) {
        return n ? n->size : 0;
    }

    long long ways(Node *n) {
        if (!n)
            return 1;
        long long wl = ways(n->l);
        long long wr = ways(n->r);
        long long wc = c(size(n->l) + size(n->r), size(n->l));
        n->size = size(n->l) + 1 + size(n->r);
        return wl * wr % MOD * wc % MOD;
    }

    void insert(int key) {
        insert(root, key);
    }

    long long ways() {
        return ways(root);
    }
};

class Solution {
public:
    int numOfWays(vector<int> &a) {
        BST bst;
        for (int value : a)
            bst.insert(value);
        return (bst.ways() + MOD - 1) % MOD;
    }
};