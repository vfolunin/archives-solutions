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

    string line;
    getline(cin, line);

    string l, r;
    for (char c : line) {
        if (c == 'L') {
            if (!l.empty()) {
                r.push_back(l.back());
                l.pop_back();
            }
        } else if (c == 'R') {
            if (!r.empty()) {
                l.push_back(r.back());
                r.pop_back();
            }
        } else if (c == 'B') {
            if (!l.empty())
                l.pop_back();
        } else {
            l.push_back(c);
        }
    }

    reverse(r.begin(), r.end());

    cout << l << r;
}