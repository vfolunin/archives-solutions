#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prefixFunction(const string &s) {
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && s[i] != s[border])
            border = p[border - 1];
        p[i] = border + (s[i] == s[border]);
    }
    return p;
}

void solve() {
    string s;
    cin >> s;

    string r = s;
    reverse(r.begin(), r.end());
    s += "#" + r;

    vector<int> p = prefixFunction(s);
    int pos = max_element(p.begin() + r.size(), p.end()) - p.begin();
    int len = p[pos];
    pos = s.size() - 1 - pos;

    cout << s.substr(pos, len) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
