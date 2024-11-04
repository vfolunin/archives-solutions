#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(string &s, vector<string> &res) {
    if (s.size() == 5) {
        res.push_back(s);
        return;
    }

    static string letters = "ÀÄÊËÎ";
    for (char c : letters) {
        s.push_back(c);
        rec(s, res);
        s.pop_back();
    }
}

bool isGood(string &s) {
    return s[2] == 'Ä' && s[3] != 'À' && s[3] != 'Î' && count(s.begin(), s.end(), 'Î') == 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string l, r;
    cin >> l >> r;
    if (l > r)
        swap(l, r);

    string s;
    vector<string> a;
    rec(s, a);

    int li = lower_bound(a.begin(), a.end(), l) - a.begin();
    int ri = upper_bound(a.begin(), a.end(), r) - a.begin();
    int res = 0;
    for (int i = li; i < ri; i++)
        res += isGood(a[i]);

    cout << res;
}