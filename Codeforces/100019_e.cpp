#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    for (char c; cin >> noskipws >> c; ) {
        if (c != '\n')
            s.push_back(c);

        if (s.size() >= 4 && s.substr(s.size() - 4) == "<BR>") {
            s.erase(s.end() - 4, s.end());
            s.push_back('\n');
        }
    }

    vector<string> stack(1);
    for (char c : s) {
        if (c == '<') {
            stack.emplace_back();
        } else if (c == '>' && stack.size() > 1) {
            stack.pop_back();
            continue;
        }
        stack.back().push_back(c);
    }

    for (string &s : stack)
        cout << s;
}