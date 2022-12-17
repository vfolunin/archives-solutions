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

    for (char op; cin >> op; ) {
        if (isdigit(op)) {
            stack.push_back(op - '0');
        } else {
            int b = stack.back();
            stack.pop_back();
            int &a = stack.back();
            if (op == '+')
                a += b;
            else if (op == '-')
                a -= b;
            else
                a *= b;
        }
    }

    cout << stack.back();
}