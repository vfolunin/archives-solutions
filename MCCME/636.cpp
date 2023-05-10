#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int size, string &s, string &stack) {
    if (s.size() == size) {
        cout << s << "\n";
        return;
    }

    if (s.size() + stack.size() < size) {
        for (char c : { '(', '[' }) {
            s.push_back(c);
            stack.push_back(c);
            rec(size, s, stack);
            s.pop_back();
            stack.pop_back();
        }
    }
    if (!stack.empty()) {
        char c = stack.back();
        s.push_back(c == '(' ? ')' : ']');
        stack.pop_back();
        rec(size, s, stack);
        s.pop_back();
        stack.push_back(c);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    string s, stack;
    rec(size, s, stack);
}