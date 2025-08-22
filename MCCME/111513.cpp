#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(string &s) {
    int remainder = 0;
    for (char c : s)
        remainder = (remainder * 10 + c - '0') % 9;
    return !remainder;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        for (int d = !i; d < 10; d++) {
            if (d == c - '0')
                continue;

            s[i] = d + '0';

            if (isGood(s))
                cout << s << "\n";
        }

        s[i] = c;
    }
}