#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    char c;
    Node *l, *r;

    Node(char c, Node *l, Node *r) : c(c), l(l), r(r) {}
};

void solve() {
    string s;
    cin >> s;

    vector<Node *> stack;
    for (char c : s) {
        if (islower(c)) {
            stack.push_back(new Node(c, 0, 0));
        } else {
            Node *a = stack.back();
            stack.pop_back();
            Node *b = stack.back();
            stack.pop_back();
            stack.push_back(new Node(c, a, b));
        }
    }

    string res;

    queue<Node *> q;
    q.push(stack.back());
    
    while (!q.empty()) {
        Node *n = q.front();
        q.pop();

        res += n->c;
        if (n->r)
            q.push(n->r);
        if (n->l)
            q.push(n->l);
    }

    reverse(res.begin(), res.end());

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}