#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getLcs(const string &a, const string &b) {
    vector<vector<int>> lcs(a.size() + 1, vector<int>(b.size() + 1));
    int res = 0;

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            res = max(res, lcs[i][j]);
        }
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    cout << 26 - getLcs(s, "abcdefghijklmnopqrstuvwxyz");
}