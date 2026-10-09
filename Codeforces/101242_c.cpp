#include <iostream>
#include <sstream>
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

    void traverse(Node *n, stringstream &ss) {
        if (!n) {
            ss << 'N';
            return;
        }
        ss << 'L';
        traverse(n->l, ss);
        ss << 'U';
        ss << 'R';
        traverse(n->r, ss);
        ss << 'U';
    }

    void insert(int key) {
        insert(root, key);
    }

    string traverse() {
        stringstream ss;
        traverse(root, ss);
        return ss.str();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int bstCount, bstSize;
    cin >> bstCount >> bstSize;

    set<string> traverses;

    for (int i = 0; i < bstCount; i++) {
        BST bst;

        for (int j = 0; j < bstSize; j++) {
            int value;
            cin >> value;
            bst.insert(value);
        }

        traverses.insert(bst.traverse());
    }

    cout << traverses.size();
}