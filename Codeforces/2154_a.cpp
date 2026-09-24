#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int width;
    string s;
    cin >> width >> width >> s;

    int res = 0, lastPos = -1e9;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            res += lastPos + width <= i;
            lastPos = i;
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}