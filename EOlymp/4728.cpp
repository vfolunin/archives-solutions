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
    cin >> s;

    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == s[i + 1]) {
            cout << s.substr(i, 2);
            return 0;
        }
    }

    for (int i = 0; i + 2 < s.size(); i++) {
        if (s[i] == s[i + 2]) {
            cout << s.substr(i, 3);
            return 0;
        }
    }

    cout << 0;
}