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

    int getSum(Node *n) {
        if (!n)
            return 0;
        return getSum(n->l) + n->key + getSum(n->r);
    }

    int getSum(Node *n, int key) {
        if (!n)
            return -1;
        else if (key == n->key)
            return getSum(n);
        else if (key < n->key)
            return getSum(n->l, key);
        else
            return getSum(n->r, key);
    }

    int getSum(int key) {
        return getSum(root, key);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, key;
    cin >> size >> key;

    BST bst;
    for (int i = 0; i < size; i++) {
        int key;
        cin >> key;

        bst.insert(key);
    }

    cout << bst.getSum(key);
}