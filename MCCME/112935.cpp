#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(string &s, int size, int balance, int limit) {
    if (s.size() == size) {
        cout << s << "\n";
        return;
    }

    if (s.size() + balance < size && balance < limit) {
        s.push_back('(');
        rec(s, size, balance + 1, limit);
        s.pop_back();
    }
    if (balance) {
        s.push_back(')');
        rec(s, size, balance - 1, limit);
        s.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, limit;
    cin >> size >> limit;

    string s;
    rec(s, size * 2, 0, limit);
}