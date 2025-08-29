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

    int res = 1e9;
    for (int add = 0; add <= s.size(); add++) {
        int cur = add;
        for (int l = add, r = s.size() - 1; l < r; l++, r--)
            cur += s[l] != s[r];

        res = min(res, cur);
    }

    cout << res;
}