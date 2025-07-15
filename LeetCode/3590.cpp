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

    int getByIndex(Node *n, int index) const {
        if (index >= getSize(n))
            return -1;
        int leftSize = getSize(n->left);
        if (leftSize > index)
            return getByIndex(n->left, index);
        else if (leftSize == index)
            return n->key;
        else
            return getByIndex(n->right, index - leftSize - 1);
    }

    void getKeys(Node *n, vector<int> &keys) {
        if (!n)
            return;
        getKeys(n->left, keys);
        keys.push_back(n->key);
        getKeys(n->right, keys);
    }

public:
    int size() const {
        return getSize(root);
    }

    int operator[](int index) const {
        return getByIndex(root, index);
    }

    void insert(int key) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        if (!b)
            b = new Node(key);
        root = merge(a, merge(b, c));
    }

    vector<int> getKeys() {
        vector<int> keys;
        getKeys(root, keys);
        return keys;
    }
};

class Solution {
    Treap rec(vector<vector<int>> &graph, int v, int xorSum, vector<int> &a, vector<vector<pair<int, int>>> &queriesOf, vector<int> &res) {
        Treap treap;
        xorSum ^= a[v];
        treap.insert(xorSum);

        for (int to : graph[v]) {
            Treap toTreap = rec(graph, to, xorSum, a, queriesOf, res);

            if (treap.size() < toTreap.size())
                swap(treap, toTreap);
            
            for (int key : toTreap.getKeys())
                treap.insert(key);
        }

        for (auto &[index, qIndex] : queriesOf[v])
            res[qIndex] = treap[index - 1];
        
        return treap;
    }

public:
    vector<int> kthSmallest(vector<int> &from, vector<int> &a, vector<vector<int>> &queries) {
        vector<vector<int>> graph(from.size());
        for (int v = 1; v < graph.size(); v++)
            graph[from[v]].push_back(v);
        
        vector<vector<pair<int, int>>> queriesOf(graph.size());
        for (int i = 0; i < queries.size(); i++)
            queriesOf[queries[i][0]].push_back({ queries[i][1], i });

        vector<int> res(queries.size());
        rec(graph, 0, 0, a, queriesOf, res);
        return res;
    }
};