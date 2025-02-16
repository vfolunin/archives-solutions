#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string s;
    if (!(cin >> s))
        return 0;

    s.insert(s.begin(), '0');

    int res = 0;
    for (int i = 0; i + 1 < s.size(); i++)
        res += s[i] != s[i + 1];

    cout << "Game #" << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}