#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(string &s) {
    string stack, open = "([{", close = ")]}";
    for (char c : s) {
        if (open.find(c) != -1)
            stack.push_back(c);
        else if (stack.empty() || open.find(stack.back()) != close.find(c))
            return 0;
        else
            stack.pop_back();
    }
    return stack.empty();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (string s; cin >> s; )
        cout << !check(s);
}