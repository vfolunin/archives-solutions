#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    for (char c; cin >> c;)
        if (isalpha(c))
            s += tolower(c);

    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == s[i + 1] || i + 2 < s.size() && s[i] == s[i + 2]) {
            cout << "Palindrome";
            return 0;
        }
    }

    cout << "Anti-palindrome";
}