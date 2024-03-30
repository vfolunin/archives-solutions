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
        if (isdigit(op[0])) {
            stack.push_back(stoi(op));
        } else {
            int b = stack.back();
            stack.pop_back();
            int &a = stack.back();
            if (op == "+")
                a += b;
            else if (op == "-")
                a -= b;
            else if (op == "*")
                a *= b;
            else
                a /= b;
        }
    }

    cout << stack.back();
}