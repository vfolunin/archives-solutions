#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int priority(char c) {
    if (c == '|' || c == '^')
        return 0;
    else if (c == '&')
        return 1;
    else
        return 2;
}

string toPostfix(string &s) {
    string postfix, stack;

    for (char c : s) {
        if (isdigit(c)) {
            postfix.push_back(c);
        } else if (c == '(') {
            stack.push_back(c);
        } else if (c == ')') {
            while (stack.back() != '(') {
                postfix.push_back(stack.back());
                stack.pop_back();
            }
            stack.pop_back();
        } else {
            while (!stack.empty() && stack.back() != '(' && priority(c) <= priority(stack.back())) {
                postfix.push_back(stack.back());
                stack.pop_back();
            }
            stack.push_back(c);
        }
    }

    postfix.insert(postfix.end(), stack.rbegin(), stack.rend());

    return postfix;
}

int eval(const string &postfix) {
    vector<int> stack;

    for (char c : postfix) {
        if (isdigit(c)) {
            stack.push_back(c - '0');
        } else if (c == '!') {
            stack.back() = !stack.back();
        } else {
            int b = stack.back();
            stack.pop_back();
            int &a = stack.back();

            if (c == '|')
                a |= b;
            else if (c == '&')
                a &= b;
            else
                a ^= b;
        }
    }

    return stack.back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    cout << eval(toPostfix(s));
}