#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(string &s) {
    int res = 0;
    for (char c : s)
        res += c - '0';
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    string res = s;

    for (int i = (int)s.size() - 2; i >= 0; i--) {
        if (s[i] == '0')
            continue;

        string candidate = s.substr(0, i) + string(1, s[i] - 1) + string(s.size() - 1 - i, '9');
        if (digitSum(res) < digitSum(candidate))
            res = candidate;
    }

    if (res.size() > 1 && res[0] == '0')
        res = res.substr(1);

    cout << res;
}