#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(string &s, int l, int r) {
    for (; l < r; l++, r--)
        if (s[l] != s[r])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    for (int size = 2; size <= s.size(); size += 2) {
        for (int l = 0, r = size - 1; r < s.size(); l++, r++) {
            if (isPalindrome(s, l, r)) {
                cout << "Even\n";
                return 0;
            }
        }
    }

    cout << "Odd\n";
}