#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

minstd_rand gen;

class Treap {
    struct Node {
        int key, priority, nodeSize, subtreeSize;
        Node *left, *right;
        Node(int key) : key(key), priority(gen()), nodeSize(1), subtreeSize(1), left(0), right(0) {}
    } *root;

    int getSubtreeSize(Node *n) const {
        return n ? n->subtreeSize : 0;
    }

    void update(Node *n) {
        if (n) {
            n->subtreeSize = getSubtreeSize(n->left) + n->nodeSize + getSubtreeSize(n->right);
        }
    }

    Node *merge(Node *a, Node *b) {
        if (!a || !b) {
            return a ? a : b;
        }
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

    int indexOf(Node *n, int key) const {
        if (!n) {
            return 0;
        } else if (n->key < key) {
            return getSubtreeSize(n->left) + n->nodeSize + indexOf(n->right, key);
        } else if (n->key == key) {
            return getSubtreeSize(n->left);
        } else {
            return indexOf(n->left, key);
        }
    }

    int getByIndex(Node *n, int index) const {
        int leftSize = getSubtreeSize(n->left);
        if (leftSize > index) {
            return getByIndex(n->left, index);
        } else if (leftSize + n->nodeSize < index) {
            return getByIndex(n->right, index - leftSize - n->nodeSize);
        } else {
            return n->key;
        }
    }

public:
    Treap() : root(0) {}

    int size() const {
        return getSubtreeSize(root);
    }

    int indexOf(int key) const {
        return indexOf(root, key);
    }

    int operator [] (int index) const {
        return getByIndex(root, index);
    }

    void insert(int key) {
        Node *less, *equal, *greater;
        split(root, key, less, equal);
        split(equal, key + 1, equal, greater);
        if (equal) {
            equal->nodeSize++;
            equal->subtreeSize++;
        } else {
            equal = new Node(key);
        }
        equal = merge(equal, greater);
        root = merge(less, equal);
    }

    void erase(int key) {
        Node *less, *equal, *greater;
        split(root, key, less, equal);
        split(equal, key + 1, equal, greater);
        if (equal) {
            equal->nodeSize--;
            equal->subtreeSize--;
            if (!equal->nodeSize) {
                equal = 0;
            }
        }
        equal = merge(equal, greater);
        root = merge(less, equal);
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    Treap l, r;
    for (int i = 0; i < n; i++)
        r.insert(v[i]);

    long long res = 0;
    for (int i = 0; i < n; i++) {
        r.erase(v[i]);

        long long lNotLess = l.size() - l.indexOf(v[i]);
        long long lNotGreater = l.indexOf(v[i] + 1);        
        long long lEqual = lNotGreater - l.indexOf(v[i]);

        long long rNotLess = r.size() - r.indexOf(v[i]);
        long long rNotGreater = r.indexOf(v[i] + 1);
        long long rEqual = lNotGreater - r.indexOf(v[i]);

        res += lNotLess * rNotGreater;
        res += lNotGreater * rNotLess;
        res -= lEqual * rEqual;

        l.insert(v[i]);
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}