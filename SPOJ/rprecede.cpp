#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int eval(const vector<string> &postfix) {
    vector<int> stack;

    for (const string &token : postfix) {
        if (isdigit(token[0])) {
            stack.push_back(stoi(token));
        } else {
            int b = stack.back();
            stack.pop_back();
            int &a = stack.back();

            if (token == "+")
                a += b;
            else if (token == "-")
                a -= b;
            else if (token == "*")
                a *= b;
            else
                a /= b;
        }
    }

    return stack.back();
}

vector<string> toPostfix(string &s) {
    vector<string> postfix, stack;
    string number;

    for (char c : s) {
        if (isdigit(c)) {
            number += c;
        } else {
            if (!number.empty()) {
                postfix.push_back(number);
                number.clear();
            }

            if (c == '(') {
                stack.push_back(string(1, c));
            } else if (c == ')') {
                while (stack.back() != "(") {
                    postfix.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
            } else if (!isspace(c)) {
                while (!stack.empty() && stack.back() != "(" && (c == '*' || c == '/' || stack.back() == "+" || stack.back() == "-")) {
                    postfix.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(string(1, c));
            }
        }
    }

    if (!number.empty())
        postfix.push_back(number);
    postfix.insert(postfix.end(), stack.rbegin(), stack.rend());

    return postfix;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    cout << eval(toPostfix(s));
}