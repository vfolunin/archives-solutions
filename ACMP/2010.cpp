#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(string &s, vector<string> &res) {
    if (s.size() == 6) {
        res.push_back(s);
        return;
    }

    static string letters = "ÂÃÎÐÑÒ";
    for (char c : letters) {
        s.push_back(c);
        rec(s, res);
        s.pop_back();
    }
}

bool isGood(string &s) {
    for (int i = 0; i + 1 < s.size(); i++)
        if (s[i] != 'Î' && s[i + 1] != 'Î')
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string target;
    cin >> target;

    string s;
    vector<string> a;
    rec(s, a);

    int res = upper_bound(a.begin(), a.end(), target) - a.begin();
    while (!isGood(a[res]))
        res++;

    cout << res + 1;
}