#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    int val = 0;
    Node *l = 0, *r = 0;
};

bool add(Node *n, bool &overwrite) {
    char c;
    cin >> c;

    if (cin.peek() == ')') {
        cin >> c;
        return 0;
    }

    int val;
    string path;
    cin >> val >> c >> path;

    for (char c : path) {
        if (c == 'L') {
            if (!n->l)
                n->l = new Node;
            n = n->l;
        } else if (c == 'R'){
            if (!n->r)
                n->r = new Node;
            n = n->r;
        }
    }

    if (n->val)
        overwrite = 1;
    n->val = val;
    return 1;
}

bool isComplete(Node *n) {
    if (!n)
        return 1;
    return n->val && isComplete(n->l) && isComplete(n->r);
}

void print(Node *n) {
    queue<Node *> q;
    q.push(n);

    while (!q.empty()) {
        Node *n = q.front();
        q.pop();

        if (n->l)
            q.push(n->l);
        if (n->r)
            q.push(n->r);

        cout << n->val << (q.empty() ? '\n' : ' ');
    }
}

bool solve() {
    while (isspace(cin.peek()))
        cin.ignore();
    if (cin.peek() == EOF)
        return 0;

    Node *root = new Node;
    bool overwrite = 0;
    while (add(root, overwrite));

    if (overwrite || !isComplete(root))
        cout << "not complete\n";
    else
        print(root);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}