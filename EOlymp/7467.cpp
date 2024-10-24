#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BST {
    struct Node {
        int key, value;
        Node *l = 0, *r = 0;
        Node(int key, int value) : key(key), value(value) {}
    } *root = 0;

    void insert(Node *&n, int key, int value) {
        if (!n) {
            n = new Node(key, value);
            return;
        }
        if (key < n->key)
            insert(n->l, key, value);
        else
            insert(n->r, key, value);
    }

    void insert(int key, int value) {
        insert(root, key, value);
    }

    bool areSymmetric(Node *a, Node *b) {
        if (!a || !b)
            return !a && !b;
        return a->value == b->value && areSymmetric(a->l, b->r) && areSymmetric(a->r, b->l);
    }

    bool isSymmetric() {
        return areSymmetric(root, root);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> keys(size);
    for (int &key : keys)
        cin >> key;

    vector<int> values(size);
    for (int &value : values)
        cin >> value;

    BST bst;
    for (int i = 0; i < size; i++)
        bst.insert(keys[i], values[i]);

    cout << bst.isSymmetric();
}