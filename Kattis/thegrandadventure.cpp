#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char complement(char c) {
    static string brackets = "$b|t*j";
    return brackets[brackets.find(c) ^ 1];
}

void solve() {
    string line;
    cin >> line;

    vector<char> stack;
    for (char c : line) {
        if (c == '.') {
            continue;
        } else if (!isalpha(c)) {
            stack.push_back(c);
        } else if (stack.empty() || stack.back() != complement(c)) {
            cout << "NO\n";
            return;
        } else {
            stack.pop_back();
        }
    }

    cout << (stack.empty() ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}