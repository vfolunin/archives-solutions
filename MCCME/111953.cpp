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

    if (s.size() % 2) {
        string l = s.substr(0, s.size() / 2);
        char m = s[s.size() / 2];
        string r = s.substr(s.size() / 2 + 1);

        if (string(l.rbegin(), l.rend()) > r) {
            cout << l << m << string(l.rbegin(), l.rend());
            return 0;
        }

        if (m != '9') {
            m++;
            cout << l << m << string(l.rbegin(), l.rend());
            return 0;
        }

        int pos = (int)l.size() - 1;
        while (pos >= 0 && l[pos] == '9')
            pos--;

        if (pos == -1) {
            l = "1" + string(l.size(), '0');
            cout << l << string(l.rbegin(), l.rend());
        } else {
            l[pos]++;
            fill(l.begin() + pos + 1, l.end(), '0');
            cout << l << "0" << string(l.rbegin(), l.rend());
        }
    } else {
        string l = s.substr(0, s.size() / 2);
        string r = s.substr(s.size() / 2);

        if (string(l.rbegin(), l.rend()) > r) {
            cout << l << string(l.rbegin(), l.rend());
            return 0;
        }

        int pos = (int)l.size() - 1;
        while (pos >= 0 && l[pos] == '9')
            pos--;

        if (pos == -1) {
            l = "1" + string(l.size(), '0');
            cout << l << string(l.rbegin() + 1, l.rend());
        } else {
            l[pos]++;
            fill(l.begin() + pos + 1, l.end(), '0');
            cout << l << string(l.rbegin(), l.rend());
        }
    }
}