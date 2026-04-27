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

    string res;
    if (s.size() % 2 == 0) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            res = s[l] + (s[r] + res);
    } else {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            res = s[r] + (s[l] + res);
        res = s[s.size() / 2] + res;
    }

    cout << res;
}