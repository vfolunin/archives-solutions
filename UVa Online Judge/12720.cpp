#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

void solve(int test) {
    string s;
    cin >> s;

    deque<char> l(s.begin(), s.begin() + s.size() / 2);
    deque<char> r(s.begin() + s.size() / 2, s.end());

    long long res = 0;
    while (!l.empty() || !r.empty()) {
        if (l.size() > r.size() || l.size() == r.size() && l.back() >= r.front()) {
            res = (res * 2 + l.back() - '0') % MOD;
            l.pop_back();
        } else {
            res = (res * 2 + r.front() - '0') % MOD;
            r.pop_front();
        }
    }

    cout << "Case #" << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}