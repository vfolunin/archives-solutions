#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    getline(cin, s);

    if (s == "#")
        return 0;

    int res = 0;
    for (int i = 0; i < s.size(); i++)
        if (isupper(s[i]))
            res += (i + 1) * (s[i] - 'A' + 1);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}