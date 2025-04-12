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
        while (l < r && !isalpha(s[l]))
            l++;
        while (l < r && !isalpha(s[r]))
            r--;

        if (s[l] != s[r]) {
            cout << "no";
            return 0;
        }
    }

    cout << "yes";
}