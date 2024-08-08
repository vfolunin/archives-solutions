#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char complement(char c) {
    return c == '(' ? ')' : ']';
}

void rec(int size, string &s, string &open) {
    if (s.size() == size) {
        cout << s << "\n";
        return;
    }

    if (!open.empty()) {
        char c = open.back();
        s.push_back(complement(c));
        open.pop_back();
        rec(size, s, open);
        s.pop_back();
        open.push_back(c);
    }
    if (s.size() + open.size() < size) {
        for (char c : { '(', '[' }) {
            s.push_back(c);
            open.push_back(c);
            rec(size, s, open);
            s.pop_back();
            open.pop_back();
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    string s, open;
    rec(size, s, open);
}