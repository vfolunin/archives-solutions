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

    string res = s;
    for (int l = 0; l < s.size(); l++)
        for (int r = l + 1; r < s.size(); r++)
            for (int m = l; m < r; m++)
                res = max(res, s.substr(0, l) + s.substr(m + 1, r - m) + s.substr(l, m - l + 1) + s.substr(r + 1));

    cout << res;
}