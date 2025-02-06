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
        ways[i][i + 1] = s[i] == s[i + 1] ? 3 : 2;

    for (int size = 3; size <= s.size(); size++)
        for (int l = 0, r = size - 1; r < s.size(); l++, r++)
            ways[l][r] = ways[l][r - 1] + ways[l + 1][r] + (s[l] == s[r] ? 1 : -ways[l + 1][r - 1]);

    cout << ways[0][s.size() - 1];
}