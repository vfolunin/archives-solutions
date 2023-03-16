#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> l(s.size());
    for (int i = 0; i < s.size(); i++)
        l[i] = (s[i] == 'R') + (i ? l[i - 1] : 0);

    vector<int> r(s.size());
    for (int i = s.size() - 1; i >= 0; i--)
        r[i] = (s[i] == 'B') + (i + 1 < s.size() ? r[i + 1] : 0);

    int res = s.size();
    for (int i = 0; i + 1 < s.size(); i++)
        if (l[i] == r[i + 1])
            res = min(res, l[i]);

    cout << string(r.front() - res, 'B') << string(l.back() - res, 'R') << "\n" << res * 2;
}