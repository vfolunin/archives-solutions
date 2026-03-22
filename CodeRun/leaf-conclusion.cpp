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
        else
            return;
    }

    void insert(int key) {
        insert(root, key);
    }

    void printLeaves(Node *n) {
        if (!n)
            return;

        printLeaves(n->l);
        if (!n->l && !n->r)
            cout << n->key << " ";
        printLeaves(n->r);
    }

    void printLeaves() {
        printLeaves(root);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BST bst;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        bst.insert(value);
    }

    bst.printLeaves();
}