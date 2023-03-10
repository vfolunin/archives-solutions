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

    for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
        while (l < r && !isalpha(s[l]))
            l++;
        while (l < r && !isalpha(s[r]))
            r--;
        if (tolower(s[l]) != tolower(s[r])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}