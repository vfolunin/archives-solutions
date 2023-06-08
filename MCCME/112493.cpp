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

    vector<long long> stack;

    for (string op; cin >> op; ) {
        if (isdigit(op[0])) {
            stack.push_back(stoll(op));
        } else {
            if (stack.empty()) {
                cout << "ERROR";
                return 0;
            }

            if (op == "DROP") {
                stack.pop_back();
            } else if (op == "DUP") {
                stack.push_back(stack.back());
            } else {
                if (stack.size() < 2) {
                    cout << "ERROR";
                    return 0;
                }

                if (op == "SWAP") {
                    swap(stack[stack.size() - 2], stack[stack.size() - 1]);
                } else if (op == "OVER") {
                    stack.push_back(stack[stack.size() - 2]);
                } else {
                    long long b = stack.back();
                    stack.pop_back();
                    long long &a = stack.back();

                    if (op == "+")
                        a += b;
                    else if (op == "-")
                        a -= b;
                    else if (op == "*")
                        a *= b;
                    else
                        a = a / b - (((a < 0) ^ (b < 0)) && (a % b));
                }
            }
        }
    }

    if (stack.empty()) {
        cout << "EMPTY";
    } else {
        for (long long value : stack)
            cout << value << " ";
    }
}