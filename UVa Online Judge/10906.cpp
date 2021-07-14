#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Expression {
    string a, op, b;
};

void print(string &name, map<string, Expression> &expr) {
    if (isdigit(name[0])) {
        cout << name;
        return;
    }
    auto &[a, op, b] = expr[name];

    if (!isdigit(a[0]) && op == "*" && expr[a].op == "+") {
        cout << "(";
        print(a, expr);
        cout << ")";
    } else {
        print(a, expr);
    }

    cout << op;

    if (!isdigit(b[0]) && (op == "*" || expr[b].op == "+")) {
        cout << "(";
        print(b, expr);
        cout << ")";
    } else {
        print(b, expr);
    }
}

void solve(int test) {
    int expressionCount;
    cin >> expressionCount;

    map<string, Expression> expr;
    string name;
    for (int i = 0; i < expressionCount; i++) {
        string a, op, b;
        cin >> name >> op >> a >> op >> b;
        expr[name] = { a, op, b };
    }

    cout << "Expression #" << test << ": ";
    print(name, expr);
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}