#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<pair<char, int>> read() {
    string s;
    cin >> s;

    vector<pair<char, int>> res;
    for (char c : s) {
        if (res.empty() || res.back().first != c)
            res.push_back({ c, 1 });
        else
            res.back().second++;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<pair<char, int>> a = read();
    vector<pair<char, int>> b = read();
    vector<pair<char, int>> c = read();

    if (a.size() != b.size() || a.size() != c.size()) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    string res;

    for (int i = 0; i < a.size(); i++) {
        if (a[i].first != b[i].first || a[i].first != c[i].first) {
            cout << "IMPOSSIBLE";
            return 0;
        };

        vector<int> sizes = { a[i].second, b[i].second, c[i].second };
        sort(sizes.begin(), sizes.end());
        res += string(sizes[1], a[i].first);
    }

    cout << res;
}