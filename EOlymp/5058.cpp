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
    else if (c == ']')
        return '[';
    else
        return '{';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    string stack;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push_back(c);
        } else if (!stack.empty() && stack.back() == complement(c)) {
            stack.pop_back();
        } else {
            cout << "no\n";
            return 0;
        }
    }

    cout << (stack.empty() ? "yes\n" : "no\n");
}