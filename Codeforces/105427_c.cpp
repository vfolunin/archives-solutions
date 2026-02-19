#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int fromRoman(string &s) {
    static const map<char, int> CODES = {
        {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}
    };

    vector<int> r(s.size());
    for (int i = s.size() - 1; i >= 0; i--) {
        r[i] = CODES.at(s[i]);
        if (i + 1 < s.size())
            r[i] = max(r[i], r[i + 1]);
    }

    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        int value = CODES.at(s[i]);
        res += value < r[i] ? -value : value;
    }
    return res;
}

void solve() {
    string s;
    cin >> s;

    cout << fromRoman(s) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}