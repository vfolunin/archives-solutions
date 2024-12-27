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
        else if (key > n->key)
            insert(n->r, key);
    }

    void insert(int key) {
        insert(root, key);
    }

    int getLeafSum(Node *n) {
        if (!n->l && !n->r)
            return n->key;
        return (n->l ? getLeafSum(n->l) : 0) + (n->r ? getLeafSum(n->r) : 0);
    }

    int getLeafSum() {
        return getLeafSum(root);
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

    cout << bst.getLeafSum();
}