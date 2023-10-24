#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void test(string &a, string &b, int from, string &res) {
    string s(max(a.size(), from + b.size()), ' ');
    for (int i = 0; i < s.size(); i++)
        s[i] = from <= i && i < from + b.size() ? b[i - from] : a[i];

    if (s.find(a) != -1 && s.find(b) != -1) {
        s[0] = toupper(s[0]);
        s[from] = toupper(s[from]);

        if (res == "" || res.size() > s.size() || res.size() == s.size() && res > s)
            res = s;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    a[0] = tolower(a[0]);
    b[0] = tolower(b[0]);

    string res;

    for (int i = 0; i <= a.size(); i++)
        test(a, b, i, res);

    for (int i = 0; i <= b.size(); i++)
        test(b, a, i, res);

    cout << res;
}