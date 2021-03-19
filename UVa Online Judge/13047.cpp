#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    cin >> s;

    int res = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '>') {
            int cur = 1;
            for (int j = i - 1; j >= 0 && s[j] == '-'; j--)
                cur++;
            res = max(res, cur);

            cur = 1;
            for (int j = i - 1; j >= 0 && s[j] == '='; j--)
                cur++;
            res = max(res, cur);
        }

        if (s[i] == '<') {
            int cur = 1;
            for (int j = i + 1; j < s.size() && s[j] == '-'; j++)
                cur++;
            res = max(res, cur);

            cur = 1;
            for (int j = i + 1; j < s.size() && s[j] == '='; j++)
                cur++;
            res = max(res, cur);
        }
    }

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}