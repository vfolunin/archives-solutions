#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct TST {
    struct Node {
        int key;
        Node *l = 0, *m = 0, *r = 0;
        Node(int key) : key(key) {}
    } *root = 0;

    int insert(Node *&n, int key) {
        if (!n) {
            n = new Node(key);
            return -1;
        }
        if (key < n->key) {
            if (n->l) {
                return insert(n->l, key);
            } else {
                insert(n->l, key);
                return n->key;
            }
        } else if (key == n->key) {
            if (n->m) {
                return insert(n->m, key);
            } else {
                insert(n->m, key);
                return n->key;
            }
        } else {
            if (n->r) {
                return insert(n->r, key);
            } else {
                insert(n->r, key);
                return n->key;
            }
        }
    }

    int insert(int key) {
        return insert(root, key);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    TST tst;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        int parent = tst.insert(value);

        if (i)
            cout << parent << "\n";
    }
}