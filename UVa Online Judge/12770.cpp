#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    cin >> s;

    if (s == "#")
        return 0;

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;

    string res;
    for (int i = 0; i < 26; i++)
        if (count[i] % 2)
            res += 'a' + i;

    if (!res.empty())
        res.pop_back();

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}