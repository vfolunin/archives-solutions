#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string replace(string s, string &a, string &b) {
    string res;
    for (int offset = 0, i = 0; offset < s.size(); ) {
        int pos = s.find(a, offset);
        if (pos == -1)
            pos = s.size();
        while (i < pos)
            res += s[i++];
        if (pos != s.size())
            res += b;
        offset = pos + a.size();
        i += a.size();
    }
    return res;
}

void rec(vector<pair<string, string>> &sub, string s, string &target, int depth, int &res) {
    if (depth > res || s.size() > target.size())
        return;
    if (s == target) {
        res = min(res, depth);
        return;
    }
    for (auto &[a, b] : sub)
        if (s.find(a) != -1)
            rec(sub, replace(s, a, b), target, depth + 1, res);
}

bool solve() {
    int subCount;
    cin >> subCount;

    if (!subCount)
        return 0;

    vector<pair<string, string>> sub(subCount);
    for (auto &[a, b] : sub)
        cin >> a >> b;

    string start, target;
    cin >> start >> target;
    int res = 1e9;

    rec(sub, start, target, 0, res);
    
    cout << (res != 1e9 ? res : -1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}