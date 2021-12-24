#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char complement(char c) {
    static string brackets = "()[]{}";
    return brackets[brackets.find(c) ^ 1];
}

void solve() {
    string s;
    cin >> s;

    string stack;
    int connectionCount = 0;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push_back(c);
        } else if (!stack.empty() && stack.back() == complement(c)) {
            stack.pop_back();
        } else {
            cout << "N\n";
            return;
        }
    }

    cout << (stack.empty() ? "S\n" : "N\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}