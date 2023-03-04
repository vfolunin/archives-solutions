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

    for (int l = 0, r = s.size() - 1; l < r; l++, r--)
        if (s[l] == s[r])
            s[l] = s[r] = '#';

    s.erase(remove(s.begin(), s.end(), '#'), s.end());

    cout << s;
}