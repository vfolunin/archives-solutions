#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    string op;
    Node *left = 0, *right = 0;

    Node(string &op, Node *left = 0, Node *right = 0) : op(op), left(left), right(right) {}

    void print() {
        if (isdigit(op[0])) {
            cout << op;
        } else {
            cout << "(";
            left->print();
            cout << op;
            right->print();
            cout << ")";
        }
    }
};

Node *rec(vector<string> &tokens) {
    string op = tokens.back();
    tokens.pop_back();

    if (isdigit(op[0]))
        return new Node(op);

    Node *r = rec(tokens);
    Node *l = rec(tokens);
    return new Node(op, l, r);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> tokens;
    for (string token; cin >> token; )
        tokens.push_back(token);

    rec(tokens)->print();
}