#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    bool ok = s.size() == 8;
    for (int i = 0; ok && i < 3; i++)
        ok &= (bool)isupper(s[i]);
    ok &= s[3] == '-';
    for (int i = 4; ok && i < 8; i++)
        ok &= (bool)isdigit(s[i]);

    if (ok) {
        static string digits = "1234567890";
        static vector<string> days = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY" };
        cout << days[digits.find(s.back()) / 2] << "\n";
    } else {
        cout << "FAILURE\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}