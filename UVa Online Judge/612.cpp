#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int inversionCount(const string &s) {
    int inv = 0;
    for (int i = 0; i < s.size(); i++)
        for (int j = i + 1; j < s.size(); j++)
            inv += s[i] > s[j];
    return inv;
}

struct String {
    string s;
    int inv;

    bool operator < (const String &that) const {
        return inv < that.inv;
    }
};

void solve(int test) {
    int len, n;
    cin >> len >> n;

    vector<String> a(n);
    for (String &s : a) {
        cin >> s.s;
        s.inv = inversionCount(s.s);
    }

    stable_sort(a.begin(), a.end());

    if (test)
        cout << "\n";
    for (String &s : a)
        cout << s.s << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}