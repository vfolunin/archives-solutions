#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string a, b;
    if (!(cin >> a >> b))
        return 0;

    vector<vector<int>> lcsLen(a.size() + 1, vector<int>(b.size() + 1));
    vector<vector<set<string>>> lcs(a.size() + 1, vector<set<string>>(b.size() + 1, {""}));
    int maxLen = 0;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] != b[j])
                continue;
            lcsLen[i + 1][j + 1] = lcsLen[i][j] + 1;
            lcs[i + 1][j + 1].clear();
            for (const string &s : lcs[i][j])
                lcs[i + 1][j + 1].insert(s + a[i]);
            maxLen = max(maxLen, lcsLen[i + 1][j + 1]);
        }
    }

    set<string> res;
    for (int i = 0; i <= a.size(); i++)
        for (int j = 0; j <= b.size(); j++)
            if (lcsLen[i][j] == maxLen)
                res.insert(lcs[i][j].begin(), lcs[i][j].end());

    if (test)
        cout << "\n";
    if (!maxLen)
        cout << "No common sequence.\n";
    else
        for (const string &s : res)
            cout << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}