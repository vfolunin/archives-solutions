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

    int cur = 0, l = 0, r = 0;
    for (char c : s) {
        cur += c == '1' ? 1 : -1;
        l = min(l, cur);
        r = max(r, cur);
    }

    cout << r - l + 1;
}