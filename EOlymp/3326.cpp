#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e6 + 3;

long long c(int n, int k) {
    static vector<vector<long long>> memo(1001, vector<long long>(1001, -1));
    long long &res = memo[n][k];
    if (res != -1)
        return res;

    if (k == 0 || k == n)
        return res = 1;

    return res = (c(n - 1, k) + c(n - 1, k - 1)) % MOD;
}

struct BST {
    struct Node {
        int key, size = 1;
        Node *l = 0, *r = 0;
        Node(int key) : key(key) {}
    } *root = 0;

    int getSize(Node *n) {
        return n ? n->size : 0;
    }

    void insert(Node *&n, int key) {
        if (!n) {
            n = new Node(key);
            return;
        }
        if (key < n->key)
            insert(n->l, key);
        else
            insert(n->r, key);
        n->size = getSize(n->l) + 1 + getSize(n->r);
    }

    void insert(int key) {
        insert(root, key);
    }

    long long traverse(Node *n) {
        if (!n)
            return 1;
        long long res = c(getSize(n->l) + getSize(n->r), getSize(n->l));
        res = res * traverse(n->l) % MOD;
        res = res * traverse(n->r) % MOD;
        return res;
    }

    long long traverse() {
        return traverse(root);
    }
};

void solve() {
    int size, maxSize;
    cin >> size >> maxSize;

    BST bst;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        bst.insert(value);
    }

    cout << c(maxSize, size) * bst.traverse() % MOD << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}