#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int jump;
    string s;
    if (!(cin >> jump >> s))
        return 0;

    for (int i = jump; i <= s.size(); i += jump)
        if (i / jump % jump)
            cout << s[i - 1];
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}