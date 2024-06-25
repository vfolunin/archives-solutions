#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int size, int i, int open, string &s) {
    if (i == size) {
        cout << s << "\n";
        return;
    }

    if (open + 1 <= size - i - 1) {
        s.push_back('(');
        rec(size, i + 1, open + 1, s);
        s.pop_back();
    }
    if (open) {
        s.push_back(')');
        rec(size, i + 1, open - 1, s);
        s.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;
    size *= 2;

    string s;
    rec(size, 0, 0, s);
}