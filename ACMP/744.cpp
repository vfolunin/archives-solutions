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

bool check(string &s) {
    string stack;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
            stack.push_back(c);
        else if (!stack.empty() && stack.back() == complement(c))
            stack.pop_back();
        else
            return 0;
    }
    return stack.empty();
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    if (s.empty()) {
        cout << "YES";
        return 0;
    }

    for (int i = 0; i < s.size(); i++) {
        if (check(s)) {
            cout << "YES";
            return 0;
        }
        rotate(s.begin(), s.begin() + 1, s.end());
    }

    cout << "NO";
}