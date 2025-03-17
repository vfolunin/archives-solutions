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

    vector<pair<char, int>> stack;
    int res = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack.push_back({ s[i], i });
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (!stack.empty() && stack.back().first == complement(s[i])) {
                res = max(res, i - stack.back().second + 1);
                stack.pop_back();
            } else {
                stack.clear();
            }
        }
    }

    cout << res;
}