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

    string token;
    while (cin >> token) {
        if (isdigit(token[0])) {
            stack.push_back(stoi(token));
        } else {
            int b = stack.back();
            stack.pop_back();
            int a = stack.back();
            stack.pop_back();

            if (token == "+")
                stack.push_back(a + b);
            else if (token == "-")
                stack.push_back(a - b);
            else
                stack.push_back(a * b);
        }
    }

    cout << stack.back();
}