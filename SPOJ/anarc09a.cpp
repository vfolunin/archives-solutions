#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string s;
    cin >> s;

    if (s[0] == '-')
        return 0;

    int balance = 0, badClose = 0;
    for (char c : s) {
        if (c == '{') {
            balance++;
        } else {
            if (balance)
                balance--;
            else
                badClose++;
        }
    }
    int badOpen = balance;

    cout << test << ". " << (badOpen + 1) / 2 + (badClose + 1) / 2 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}