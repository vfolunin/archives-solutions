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

    if (s[0] == '-') {
        cout << "-";
        s.erase(s.begin());
    }

    string res;
    for (char c : s) {
        int value = c - '0';
        string part;
        for (int j = 0; j < 3; j++) {
            part += value % 2 + '0';
            value /= 2;
        }
        res += { part.rbegin(), part.rend() };
    }

    while (res.size() > 1 && res[0] == '0')
        res.erase(res.begin());

    cout << res;
}