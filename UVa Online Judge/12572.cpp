#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

bool solve() {
    string s;
    if (!(cin >> s >> s))
        return 0;

    vector<int> stack, r(s.size());
    for (int i = 0; i < s.size(); i++) {
        while (!stack.empty() && s[stack.back()] > s[i]) {
            r[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }
    while (!stack.empty()) {
        r[stack.back()] = s.size();
        stack.pop_back();
    }

    vector<int> l(s.size());
    for (int i = s.size() - 1; i >= 0; i--) {
        while (!stack.empty() && s[stack.back()] >= s[i]) {
            l[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }
    while (!stack.empty()) {
        l[stack.back()] = -1;
        stack.pop_back();
    }

    long long res = 0;
    for (int i = 0; i < s.size(); i++)
        res = (res + (s[i] - '0') * (i - l[i]) * (r[i] - i)) % MOD;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}