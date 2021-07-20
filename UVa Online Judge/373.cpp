#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool test(char a, char b) {
    return tolower(a) == b;
}

bool solve() {
    string s;
    if (!getline(cin, s))
        return 0;

    s = " " + s + "  ";

    while (1) {
        bool changed = 0;

        for (int i = 0; i < s.size(); i++) {
            int p = i;
            while (test(s[p], 'p') && test(s[p + 1], 'g') &&
                   !test(s[p - 1], 'e') && (!test(s[p + 2], 'u') || !test(s[p + 3], 'k'))) {
                swap(s[p], s[p + 1]);
                p--;
                changed = 1;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            int g = i;
            while (test(s[g], 'g') && test(s[g + 1], 'p') &&
                   (test(s[g - 1], 'e') || (test(s[g + 2], 'u') && test(s[g + 3], 'k')))) {
                swap(s[g], s[g + 1]);
                g++;
                changed = 1;
            }
        }

        if (!changed)
            break;
    }

    cout << s.substr(1, s.size() - 3) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}