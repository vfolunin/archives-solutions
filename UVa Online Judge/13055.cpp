#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int opCount;
    cin >> opCount;

    vector<string> stack;
    for (int i = 0; i < opCount; i++) {
        string op;
        cin >> op;

        if (op == "Sleep") {
            stack.emplace_back();
            cin >> stack.back();
        } else if (op == "Kick") {
            if (!stack.empty())
                stack.pop_back();
        } else {
            cout << (stack.empty() ? "Not in a dream" : stack.back()) << "\n";
        }
    }
}