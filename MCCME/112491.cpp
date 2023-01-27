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

    vector<int> stack;

    char op;
    while (cin >> op) {
        if (op == '+') {
            int value;
            cin >> value;
            stack.push_back(value);
        } else if (!stack.empty()) {
            stack.pop_back();
        } else {
            cout << "ERROR";
            return 0;
        }
    }

    if (!stack.empty()) {
        for (int value : stack)
            cout << value << " ";
    } else {
        cout << "EMPTY";
    }
}