#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 9999991;

long long c(int n, int m) {
    static vector<vector<long long>> memo(21, vector<long long>(21, -1));
    long long &res = memo[n][m];
    if (res != -1)
        return res;

    if (n < m)
        return res = 0;
    if (!n || !m)
        return res = 1;

    return res = c(n - 1, m) + c(n - 1, m - 1) % MOD;
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
        return wl * wr * wc % MOD;
    }

    void insert(int key) {
        insert(root, key);
    }

    long long ways() {
        return ways(root);
    }
};

void solve() {
    int n;
    cin >> n;

    BST bst;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bst.insert(x);
    }

    cout << bst.ways() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}