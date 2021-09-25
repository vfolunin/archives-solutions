#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    cin >> s;

    string stack;
    for (char c : s) {
        stack.push_back(c);
        if (stack.size() >= 2 &&
            stack[stack.size() - 3] == '1' &&
            stack[stack.size() - 2] == '0' &&
            stack[stack.size() - 1] == '0') {
            for (int i = 0; i < 3; i++)
                stack.pop_back();
        }
    }

    cout << "Case " << test << ": ";
    cout << (stack.empty() ? "yes\n" : "bo\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}