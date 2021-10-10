#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    int balance = 0;
    for (char c : s) {
        if (c == '(')
            balance++;
        else if (c == ')')
            balance--;

        if (balance < 0) {
            cout << "incorrect\n";
            return 1;
        }
    }

    cout << (!balance ? "correct\n" : "incorrect\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}