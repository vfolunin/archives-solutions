#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    sort(s.rbegin(), s.rend());
    long long a = stoll(s);

    reverse(s.begin(), s.end());
    int p = 0;
    while (s[p] == '0')
        p++;
    reverse(s.begin(), s.begin() + p + 1);
    long long b = stoll(s);

    long long r = a - b;

    cout << a << " - " << b << " = " << r << " = 9 * " << r / 9 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}