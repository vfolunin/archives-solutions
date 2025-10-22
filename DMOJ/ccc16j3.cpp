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

    int res = 0;
    for (int l = 0; l < s.size(); l++)
        for (int r = l; r < s.size(); r++)
            if (isPalindrome(s, l, r))
                res = max(res, r - l + 1);

    cout << res;
}