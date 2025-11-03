#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    cin >> s;

    if (s == "halt")
        return 0;

    string button = "22233344455566677778889999";
    string pressCount = "12312312312312312341231234";

    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i && button[s[i - 1] - 'a'] == button[s[i] - 'a'])
            res += 2;
        res += pressCount[s[i] - 'a'] - '0';
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}