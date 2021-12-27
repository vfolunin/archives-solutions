#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    char val;
    Node *l = 0, *r = 0;
};

void reconstruct(Node *n, int size, string &s, int &i) {
    if (size == 1) {
        n->val = s[i++];
        return;
    }

    int treeSize = 0, lastLevelSize = 1;
    while (treeSize + lastLevelSize <= size) {
        treeSize += lastLevelSize;
        lastLevelSize *= 2;
    }
    int leftSize = treeSize / 2;
    leftSize += min(size - treeSize, lastLevelSize / 2);
    int rightSize = size - 1 - leftSize;

    if (leftSize)
        reconstruct(n->l = new Node, leftSize, s, i);
    n->val = s[i++];
    if (rightSize)
        reconstruct(n->r = new Node, rightSize, s, i);
}

void levelOrder(Node *root) {
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *n = q.front();
        q.pop();

        cout << n->val;
        if (n->l)
            q.push(n->l);
        if (n->r)
            q.push(n->r);
    }
}

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    cin.ignore();
    string line;
    getline(cin, line);

    Node *root = new Node;
    int i = 0;
    reconstruct(root, size, line, i);

    levelOrder(root);
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}