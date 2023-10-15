#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char complement(char c) {
    if (c == ')')
        return '(';
    else
        return '[';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    string stack;
    int res = 0;
    for (char c : s) {
        if (c == '(' || c == '[') {
            stack.push_back(c);
        } else if (!stack.empty()) {
            res += stack.back() != complement(c);
            stack.pop_back();
        } else {
            cout << -1;
            return 0;
        }
    }

    cout << (stack.empty() ? res : -1);
}