#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BST {
    struct Node {
        int key;
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

    void insert(int key) {
        insert(root, key);
    }

    bool isLeaf(Node *n) {
        return n && !n->l && !n->r;
    }

    int leftLeafSum(Node *n) {
        if (!n)
            return 0;
        int res = 0;
        if (isLeaf(n->l))
            res += n->l->key;
        res += leftLeafSum(n->l);
        res += leftLeafSum(n->r);
        return res;
    }

    int leftLeafSum() {
        return leftLeafSum(root);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    BST bst;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        bst.insert(value);
    }

    cout << bst.leftLeafSum();
}