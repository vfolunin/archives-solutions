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

    string token;
    while (cin >> token) {
        if (isdigit(token[0])) {
            stack.push_back(stoll(token));
        } else {
            if (stack.size() < 2) {
                cout << "ERROR";
                return 0;
            }

            long long b = stack.back();
            stack.pop_back();
            long long a = stack.back();
            stack.pop_back();

            if (token == "+") {
                stack.push_back(a + b);
            } else if (token == "-") {
                stack.push_back(a - b);
            } else if (token == "*") {
                stack.push_back(a * b);
            } else if (!b) {
                cout << "ERROR";
                return 0;
            } else {
                int res = a / b;
                if (res < 0 && a % b)
                    res--;
                stack.push_back(res);
            }
        }
    }

    if (stack.size() == 1)
        cout << stack.back();
    else
        cout << "ERROR";
}