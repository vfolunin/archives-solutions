#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    int val = 0;
    Node *l = 0, *r = 0;
};

void skipSpaces() {
    while (isspace(cin.peek()))
        cin.get();
}

int readInt() {
    int sign = 1, res = 0;
    skipSpaces();
    if (cin.peek() == '-') {
        sign = -1;
        cin.get();
    }
    while (isdigit(cin.peek()))
        res = res * 10 + cin.get() - '0';
    return sign * res;
}

Node *readTree() {
    Node *n = 0;
    skipSpaces();
    cin.get();
    skipSpaces();
    if (cin.peek() != ')') {
        n = new Node();
        n->val = readInt();
        n->l = readTree();
        n->r = readTree();
    }
    skipSpaces();
    cin.get();
    return n;
}

bool dfs(Node *n, int sum, int targetSum) {
    if (!n)
        return 0;
    if (!n->l && !n->r)
        return sum + n->val == targetSum;
    return dfs(n->l, sum + n->val, targetSum) || dfs(n->r, sum + n->val, targetSum);
}

bool solve() {
    int targetSum;
    if (!(cin >> targetSum))
        return 0;

    Node *root = readTree();
    cout << (dfs(root, 0, targetSum) ? "yes\n" : "no\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}