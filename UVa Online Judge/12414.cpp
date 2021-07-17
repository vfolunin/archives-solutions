#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string yuanfen(string &s, int base) {
    string num;
    for (char c : s)
        num += to_string(base + c - 'A');

    while (num != "100" && num.size() > 2) {
        string nextNum;
        for (int i = 0; i + 1 < num.size(); i++)
            nextNum += (num[i] - '0' + num[i + 1] - '0') % 10 + '0';
        num = nextNum;
    }

    return num;
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    for (int i = 1; i <= 10000; i++) {
        if (yuanfen(s, i) == "100") {
            cout << i << "\n";
            return 1;
        }
    }

    cout << ":(\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}