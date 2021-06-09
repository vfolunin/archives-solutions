#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!getline(cin, s))
        return 0;

    set<string> op = { "(", "[", "{", "<", "(*" };
    map<string, string> cl = { {")", "("}, {"]", "["}, {"}", "{"}, {">", "<"}, {"*)", "(*"} };

    vector<string> stack;
    int pos = 1;
    for (int i = 0; i < s.size(); i++, pos++) {
        string token(1, s[i]);
        if (i + 1 < s.size() && (s[i] == '(' && s[i + 1] == '*' || s[i] == '*' && s[i + 1] == ')'))
            token += s[++i];
        
        if (op.count(token)) {
            stack.push_back(token);
        } else if (cl.count(token)) {
            if (stack.empty() || stack.back() != cl[token]) {
                cout << "NO " << pos << "\n";
                return 1;
            } else {
                stack.pop_back();
            }
        }
    }
    if (!stack.empty()) {
        cout << "NO " << pos << "\n";
        return 1;
    }

    cout << "YES\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}