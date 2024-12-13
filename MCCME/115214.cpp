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

    int h, n;
    cin >> h >> n;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    for (string &s : a) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
            if (s[l] != s[r]) {
                s[l] = s[r] = 'X';
                n--;
            }
        }
    }

    if (n < 0 || n % 2) {
        cout << "Impossible";
        return 0;
    }

    for (string &s : a) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
            if (s[l] == '.' && n) {
                s[l] = s[r] = 'X';
                n -= 2;
            }
        }
    }

    if (n) {
        cout << "Impossible";
    } else {
        for (string &s : a)
            cout << s << "\n";
    }
}