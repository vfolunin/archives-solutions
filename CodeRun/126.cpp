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

    void print(Node *n) {
        if (!n)
            return;
        print(n->l);
        if ((n->l != 0) ^ (n->r != 0))
            cout << n->key << "\n";
        print(n->r);
    }

    void print() {
        print(root);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BST bst;

    while (true) {
        int value;
        cin >> value;

        if (value == 0)
            break;

        bst.insert(value);
    }

    bst.print();
}