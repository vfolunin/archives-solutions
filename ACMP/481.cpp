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

    vector<vector<long long>> ways(s.size(), vector<long long>(s.size()));

    for (int i = 0; i < s.size(); i++)
        ways[i][i] = 1;

    for (int i = 0; i + 1 < s.size(); i++)
        ways[i][i + 1] = 2 + (s[i] == s[i + 1]);

    for (int len = 3; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            ways[l][r] = ways[l + 1][r] + ways[l][r - 1] - ways[l + 1][r - 1];
            if (s[l] == s[r])
                ways[l][r] += ways[l + 1][r - 1] + 1;
        }
    }

    cout << ways[0][s.size() - 1];
}