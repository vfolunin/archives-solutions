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

    if (s == "0")
        return 0;

    vector<int> a = { 1, 1, 2, 6, 24, 120 };
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res += (s[i] - '0') * a[s.size() - i];

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}