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

    vector<long long> ways(s.size() + 1);
    ways[0] = 1;

    for (int i = 1; i <= s.size(); i++) {
        if (s[i - 1] != '0')
            ways[i] += ways[i - 1];
        if (i >= 2 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26)
            ways[i] += ways[i - 2];
    }

    cout << ways[s.size()] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}