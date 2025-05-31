#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int size, string &s) {
    if (s.size() == size) {
        cout << s << "\n";
        return;
    }

    for (int i = 1; i <= 3; i++) {
        s.push_back(i + '0');
        rec(size, s);
        s.pop_back();
    }
}

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    string s;
    rec(size, s);
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}