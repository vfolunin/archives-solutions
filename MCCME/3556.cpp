#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class BST {
    struct Node {
        int key;
        Node *l = 0, *r = 0;

        Node(int key) : key(key) {}
    } *root = 0;

    bool contains(Node *n, int key) {
        if (!n)
            return 0;
        if (key == n->key)
            return 1;
        if (key < n->key)
            return contains(n->l, key);
        else
            return contains(n->r, key);
    }

    bool insert(Node *&n, int key) {
        if (!n) {
            n = new Node(key);
            return 1;
        }
        if (key == n->key)
            return 0;
        if (key < n->key)
            return insert(n->l, key);
        else
            return insert(n->r, key);
    }

    void print(Node *n, int level) {
        if (!n)
            return;
        print(n->l, level + 1);
        for (int i = 0; i < level; i++)
            cout << ".";
        cout << n->key << "\n";
        print(n->r, level + 1);
    }

public:
    bool contains(int key) {
        return contains(root, key);
    }

    bool insert(int key) {
        return insert(root, key);
    }

    void print() {
        print(root, 0);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BST bst;

    for (string op; cin >> op; ) {
        if (op == "SEARCH") {
            int key;
            cin >> key;
            cout << (bst.contains(key) ? "YES\n" : "NO\n");
        } else if (op == "ADD") {
            int key;
            cin >> key;
            cout << (bst.insert(key) ? "DONE\n" : "ALREADY\n");
        } else {
            bst.print();
        }
    }
}