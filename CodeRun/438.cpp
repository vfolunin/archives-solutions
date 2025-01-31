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

bool haveEqualElements(vector<pair<char, int>> &a, vector<pair<char, int>> &b) {
    if (a.size() != b.size())
        return 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i].first != b[i].first)
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<pair<char, int>> a = read();
    vector<pair<char, int>> b = read();
    vector<pair<char, int>> c = read();

    if (!haveEqualElements(a, b) || !haveEqualElements(a, c)) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int i = 0; i < a.size(); i++) {
        vector<int> count = { a[i].second, b[i].second, c[i].second };
        sort(count.begin(), count.end());
        cout << string(count[1], a[i].first);
    }
}