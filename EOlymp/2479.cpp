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

void solve() {
    string s;
    getline(cin, s);

    string stack;
    for (char c : s) {
        if (c == '(' || c == '[') {
            stack.push_back(c);
        } else if (!stack.empty() && stack.back() == complement(c)) {
            stack.pop_back();
        } else {
            cout << "No\n";
            return;
        }
    }

    cout << (stack.empty() ? "Yes\n" : "No\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.get();

    for (int i = 0; i < n; i++)
        solve();
}