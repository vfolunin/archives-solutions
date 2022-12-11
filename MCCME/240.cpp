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
    cin >> s;

    s.erase(remove_if(s.begin(), s.end(), [](char c) {
        static string vowels = "aeiouy";
        return vowels.find(c) != -1;
    }), s.end());

    cout << (isPalindrome(s) ? "YES" : "NO");
}