#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(string s) {
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

    for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
        if (s[l] != s[r]) {
            string sl = s;
            sl.erase(sl.begin() + l);
            if (isPalindrome(sl)) {
                cout << "yes\n" << sl;
                return 0;
            }

            string sr = s;
            sr.erase(sr.begin() + r);
            if (isPalindrome(sr)) {
                cout << "yes\n" << sr;
                return 0;
            }

            cout << "no";
            return 0;
        }
    }

    s.erase(s.begin() + s.size() / 2);
    cout << "yes\n" << s;
}