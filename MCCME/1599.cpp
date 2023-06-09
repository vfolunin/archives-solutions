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
    getline(cin, s);

    for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
        while (l < r && s[l] == ' ')
            l++;
        while (l < r && s[r] == ' ')
            r--;
        if (l < r && s[l] != s[r] && abs(s[l] - s[r]) != 32) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}