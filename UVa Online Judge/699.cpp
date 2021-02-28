#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    int val;
    Node *l = 0, *r = 0;

    Node() {
        cin >> val;
        if (val == -1) {
            val = 0;
        } else {
            l = new Node;
            r = new Node;
        }
    }
};

void dfs(Node *n, map<int, int> &m, int x) {
    if (!n)
        return;
    m[x] += n->val;
    dfs(n->l, m, x - 1);
    dfs(n->r, m, x + 1);
}

bool solve(int test) {
    Node n;

    if (!n.val)
        return 0;

    map<int, int> m;
    dfs(&n, m, 0);
    m.erase(m.begin());
    m.erase(--m.end());

    cout << "Case " << test << ":\n";
    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->second << (next(it) != m.end() ? ' ' : '\n');
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}