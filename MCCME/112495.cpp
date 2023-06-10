#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<double> stack;

    string token;
    while (cin >> token) {
        if (isdigit(token[0])) {
            stack.push_back(stod(token));
        } else {
            if (stack.empty()) {
                cout << "ERROR";
                return 0;
            }

            double &a = stack.back();

            if (token == "abs") {
                a = abs(a);
            } else if (token == "sin") {
                a = sin(a);
            } else if (token == "cos") {
                a = cos(a);
            } else if (token == "sqrt") {
                if (a < 0) {
                    cout << "ERROR";
                    return 0;
                }
                a = sqrt(a);
            } else {

                if (stack.size() < 2) {
                    cout << "ERROR";
                    return 0;
                }

                double b = stack.back();
                stack.pop_back();
                double &a = stack.back();

                if (token == "+") {
                    a += b;
                } else if (token == "-") {
                    a -= b;
                } else if (token == "*") {
                    a *= b;
                } else if (token == "/") {
                    if (!b) {
                        cout << "ERROR";
                        return 0;
                    }
                    a /= b;
                }
            }
        }
    }

    if (stack.size() == 1) {
        cout.precision(3);
        cout << fixed << stack.back();
    } else {
        cout << "ERROR";
    }
}