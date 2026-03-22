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

    string op;
    while (cin >> op) {
        if (op == "push") {
            int value;
            cin >> value;
            cout << "ok\n";
            stack.push_back(value);
        } else if (op == "pop") {
            if (stack.empty()) {
                cout << "error\n";
            } else {
                cout << stack.back() << "\n";
                stack.pop_back();
            }
        } else if (op == "back") {
            if (stack.empty())
                cout << "error\n";
            else
                cout << stack.back() << "\n";
        } else if (op == "size") {
            cout << stack.size() << "\n";
        } else if (op == "clear") {
            cout << "ok\n";
            stack.clear();
        } else {
            cout << "bye\n";
            break;
        }
    }
}