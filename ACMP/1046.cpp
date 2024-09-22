#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BST {
    struct Node {
        char key;
        Node *left = 0, *right = 0;

        Node(char c) : key(c) {}
    } *root = 0;

    void insert(Node *&n, char key) {
        if (!n)
            n = new Node(key);
        else if (key < n->key)
            insert(n->left, key);
        else
            insert(n->right, key);
    }

    void insert(char key) {
        insert(root, key);
    }

    void print(Node *n) {
        if (!n)
            return;
        cout << n->key;
        print(n->left);
        print(n->right);
    }

    void print() {
        print(root);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a;
    for (string s; cin >> s && s != "*"; )
        a.push_back(s);

    BST bst;
    for (int i = a.size() - 1; i >= 0; i--)
        for (char c : a[i])
            bst.insert(c);

    bst.print();
}