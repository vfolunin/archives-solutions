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

    s = string(32 - s.size(), s[0]) + s;

    int res = 0;
    for (int bit = 0; bit < s.size(); bit++)
        res += (s[s.size() - 1 - bit] == '1') << bit;

    cout << res;
}