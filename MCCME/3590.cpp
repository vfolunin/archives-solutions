#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(string &s) {
    for (int l = 0, r = s.size() - 1; l < r; l++, r--)
        if (s[l] != s[r])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    string s;
    cin >> s >> s;

    cout << (isPalindrome(s) || s.size() % 2 ? 1 : 2);
}