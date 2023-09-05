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

    for (int l = 0, r = s.size() - 1; l <= r; l++, r--) {
        if (s[l] == '?' || s[r] == '?') {
            s[l] = s[r] = (s[l] == '1' || s[r] == '1' ? '1' : '0');
        } else if (s[l] != s[r]) {
            cout << "NO SOLUTION";
            return 0;
        }
    }

    cout << s;
}