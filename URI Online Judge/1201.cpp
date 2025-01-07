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

    bool find(Node *n, int key) {
        if (!n)
            return 0;
        if (n->key == key)
            return 1;
        return find(key < n->key ? n->l : n->r, key);
    }

    Node *predecessor(Node *n) {
        n = n->l;
        while (n->r)
            n = n->r;
        return n;
    }

    void erase(Node *&n, int key) {
        if (!n)
            return;
        if (key == n->key) {
            if (!n->l || !n->r) {
                n = n->l ? n->l : n->r;
            } else {
                Node *p = predecessor(n);
                n->key = p->key;
                erase(n->l, p->key);
            }
            return;
        }
        if (key < n->key)
            erase(n->l, key);
        else
            erase(n->r, key);
    }

    void preorder(Node *n, bool &first) {
        if (!n)
            return;
        if (first)
            first = 0;
        else
            cout << " ";
        cout << n->key;
        preorder(n->l, first);
        preorder(n->r, first);
    }

    void inorder(Node *n, bool &first) {
        if (!n)
            return;
        inorder(n->l, first);
        if (first)
            first = 0;
        else
            cout << " ";
        cout << n->key;
        inorder(n->r, first);
    }

    void postorder(Node *n, bool &first) {
        if (!n)
            return;
        postorder(n->l, first);
        postorder(n->r, first);
        if (first)
            first = 0;
        else
            cout << " ";
        cout << n->key;
    }

    void insert(int key) {
        insert(root, key);
    }

    void erase(int key) {
        erase(root, key);
    }

    void preorder() {
        bool first = 1;
        preorder(root, first);
    }

    void inorder() {
        bool first = 1;
        inorder(root, first);
    }

    void postorder() {
        bool first = 1;
        postorder(root, first);
    }

    bool find(int key) {
        return find(root, key);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BST bst;

    string op;
    while (cin >> op) {
        if (op == "I") {
            int key;
            cin >> key;
            bst.insert(key);
        } else if (op == "P") {
            int key;
            cin >> key;
            cout << key << (bst.find(key) ? "" : " nao") << " existe\n";
        } else if (op == "R") {
            int key;
            cin >> key;
            bst.erase(key);
        } else if (op == "PREFIXA") {
            bst.preorder();
            cout << "\n";
        } else if (op == "INFIXA") {
            bst.inorder();
            cout << "\n";
        } else {
            bst.postorder();
            cout << "\n";
        }
    }
}