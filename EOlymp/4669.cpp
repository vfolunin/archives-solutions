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

    string s, res;
    for (char c; cin >> c; ) {
        if (auto it = find(s.begin(), s.end(), c); it != s.end())
            s.erase(s.begin(), it + 1);
        s += c;
        if (res.size() < s.size())
            res = s;
    }
    cout << res;
}