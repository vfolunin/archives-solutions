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
    for (string op; cin >> op; ) {
        if (op == "push") {
            int value;
            cin >> value;
            stack.push_back(value);
        } else if (op == "pop") {
            stack.pop_back();
        } else if (!stack.empty()) {
            cout << stack.back() << "\n";
        }
    }
}