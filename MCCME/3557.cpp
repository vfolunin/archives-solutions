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

    Node *predecessor(Node *n) {
        n = n->l;
        while (n->r)
            n = n->r;
        return n;
    }

    bool erase(Node *&n, int key) {
        if (!n)
            return 0;
        if (key == n->key) {
            if (!n->l || !n->r) {
                n = n->l ? n->l : n->r;
            } else {
                Node *pred = predecessor(n);
                n->key = pred->key;
                erase(n->l, pred->key);
            }
            return 1;
        }
        if (key < n->key)
            return erase(n->l, key);
        else
            return erase(n->r, key);
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

    bool erase(int key) {
        return erase(root, key);
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
        } else if (op == "DELETE") {
            int key;
            cin >> key;
            cout << (bst.erase(key) ? "DONE\n" : "CANNOT\n");
        } else {
            bst.print();
        }
    }
}