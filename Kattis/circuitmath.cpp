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

    int variableCount;
    cin >> variableCount;

    vector<int> variables(variableCount);
    for (int &variable : variables) {
        char c;
        cin >> c;
        variable = c == 'T';
    }

    vector<int> stack;

    char c;
    while (cin >> c) {
        if (isalpha(c)) {
            stack.push_back(variables[c - 'A']);
        } else {
            int a = stack.back();
            stack.pop_back();
            if (c == '*' || c == '+') {
                int b = stack.back();
                stack.pop_back();
                stack.push_back(c == '*' ? a && b : a || b);
            } else {
                stack.push_back(!a);
            }
        }
    }

    cout << (stack.back() ? "T" : "F");
}