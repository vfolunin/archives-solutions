#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string s;
    cin >> s;

    if (s == "end")
        return 0;

    vector<string> stacks;
    for (char c : s) {
        bool found = 0;
        for (string &stack : stacks) {
            if (stack.back() >= c) {
                stack += c;
                found = 1;
                break;
            }
        }
        if (!found)
            stacks.emplace_back(1, c);
    }

    cout << "Case " << test << ": " << stacks.size() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}