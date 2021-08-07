#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void print(string &s, int l, int r, vector<vector<int>> &mid) {
    if (l > r)
        return;

    if (l == r) {
        cout << (s[l] == '(' || s[l] == ')' ? "()" : "[]");
        return;
    }

    if (mid[l][r] == -1) {
        cout << s[l];
        print(s, l + 1, r - 1, mid);
        cout << s[r];
        return;
    }

    print(s, l, mid[l][r], mid);
    print(s, mid[l][r] + 1, r, mid);
}

void solve(int test) {
    string s;
    getline(cin, s);
    getline(cin, s);

    vector<vector<int>> add(s.size(), vector<int>(s.size()));
    vector<vector<int>> mid(s.size(), vector<int>(s.size(), -2));

    for (int i = 0; i < s.size(); i++)
        add[i][i] = 1;

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            add[l][r] = 1e9;

            if (s[l] == '(' && s[r] == ')' || s[l] == '[' && s[r] == ']') {
                add[l][r] = add[l + 1][r - 1];
                mid[l][r] = -1;
            }

            for (int m = l; m < r; m++) {
                if (add[l][r] > add[l][m] + add[m + 1][r]) {
                    add[l][r] = add[l][m] + add[m + 1][r];
                    mid[l][r] = m;
                }
            }
        }
    }

    if (test)
        cout << "\n";
    print(s, 0, s.size() - 1, mid);
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve(i);
}