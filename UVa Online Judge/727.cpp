#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int priority(char c) {
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

void solve(int test) {
    string infix;
    while (1) {
        string line;
        getline(cin, line);
        if (line.empty())
            break;
        infix.push_back(line[0]);
    }

    string ops, postfix;
    for (char c : infix) {
        if (isdigit(c)) {
            postfix.push_back(c);
        } else if (c == '(') {
            ops.push_back(c);
        } else if (c == ')') {
            while (ops.back() != '(') {
                postfix.push_back(ops.back());
                ops.pop_back();
            }
            ops.pop_back();
        } else {
            while (!ops.empty() && priority(ops.back()) >= priority(c)) {
                postfix.push_back(ops.back());
                ops.pop_back();
            }
            ops.push_back(c);
        }
    }
    
    while (!ops.empty()) {
        postfix.push_back(ops.back());
        ops.pop_back();
    }

    if (test)
        cout << "\n";
    cout << postfix << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}