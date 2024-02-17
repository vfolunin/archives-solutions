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
    cin >> s;

    bool revMode = 0;
    string rev;

    for (char c : s) {
        if (c == '(') {
            revMode = 1;
        } else if (c == ')') {
            reverse(rev.begin(), rev.end());
            cout << rev;
            rev.clear();
            revMode = 0;
        } else if (revMode) {
            rev += c;
        } else {
            cout << c;
        }
    }
}