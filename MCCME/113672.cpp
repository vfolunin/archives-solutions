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

    for (string s; cin >> s; ) {
        int l = 0;
        while (s[l] == '\'')
            l++;

        int r = 0;
        while (s[s.size() - 1 - r] == '\'')
            r++;

        cout << s.substr(l * 2, s.size() - (l + r) * 2);
    }
}