#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    char op;
    Node *l = 0, *r = 0;

    bool eval(int mask) {
        if (op == 'K')
            return l->eval(mask) && r->eval(mask);
        if (op == 'A')
            return l->eval(mask) || r->eval(mask);
        if (op == 'N')
            return !l->eval(mask);
        if (op == 'C')
            return !l->eval(mask) || r->eval(mask);
        if (op == 'E')
            return l->eval(mask) == r->eval(mask);
        return mask & (1 << (op - 'p'));
    }
};

Node *make(string &s, int &i) {
    Node *n = new Node;
    n->op = s[i];
    if (isupper(s[i])) {
        n->l = make(s, ++i);
        if (n->op != 'N')
            n->r = make(s, ++i);
    }
    return n;
}

bool solve() {
    string s;
    cin >> s;

    if (s == "0")
        return 0;

    int i = 0;
    Node *n = make(s, i);

    int res = 1;
    for (int mask = 0; mask < 32; mask++)
        res &= n->eval(mask);

    cout << (res ? "tautology\n" : "not\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}