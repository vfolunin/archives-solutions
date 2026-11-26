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

    string s;
    cin >> s >> s;

    string stack;
    for (char c : s) {
        if (!stack.empty() && stack.back() == c)
            stack.pop_back();
        else
            stack.push_back(c);
    }

    cout << (stack.empty());
}