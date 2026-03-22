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

    int insert(Node *&n, int key) {
        if (!n) {
            n = new Node(key);
            return 1;
        }
        if (key < n->key)
            return 1 + insert(n->l, key);
        else if (key > n->key)
            return 1 + insert(n->r, key);
        else
            return -1e9;
    }

    int insert(int key) {
        return insert(root, key);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BST bst;

    for (int value; cin >> value && value; ) {
        int depth = bst.insert(value);
        if (depth > 0)
            cout << depth << " ";
    }
}