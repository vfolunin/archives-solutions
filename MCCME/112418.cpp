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

    for (int l = 0, r = 0; r <= s.size(); r++) {
        if (r == s.size() || !isalpha(s[r])) {
            int shift = r - l;
            for (; l < r; l++) {
                if (isupper(s[l]))
                    cout << (char)((s[l] - 'A' + shift) % 26 + 'A');
                else
                    cout << (char)((s[l] - 'a' + shift) % 26 + 'a');
            }
            l++;
            if (r < s.size())
                cout << s[r];
        }
    }
}