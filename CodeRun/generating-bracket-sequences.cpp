#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(string &s, int size, int balance) {
    if (s.size() == size) {
        cout << s << "\n";
        return;
    }

    if (s.size() + balance < size) {
        s.push_back('(');
        rec(s, size, balance + 1);
        s.pop_back();
    }
    if (balance) {
        s.push_back(')');
        rec(s, size, balance - 1);
        s.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    string s;
    rec(s, size * 2, 0);
}