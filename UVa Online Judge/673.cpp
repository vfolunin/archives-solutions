#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void solve() {
    string s;
    getline(cin, s);

    vector<char> stack;
    for (char c : s) {
        if (c == '(' || c == '[') {
            stack.push_back(c);
        } else if (c == ')') {
            if (!stack.empty() && stack.back() == '(') {
                stack.pop_back();
            } else {
                cout << "No\n";
                return;
            }
        } else {
            if (!stack.empty() && stack.back() == '[') {
                stack.pop_back();
            } else {
                cout << "No\n";
                return;
            }
        }
    }

    cout << (stack.empty() ? "Yes\n" : "No\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}