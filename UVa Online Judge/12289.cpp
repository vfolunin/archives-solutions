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

    if (s.size() == 5)
        cout << "3\n";

    int errors = 0;
    errors += s[0] != 'o';
    errors += s[1] != 'n';
    errors += s[2] != 'e';

    if (errors <= 1)
        cout << "1\n";
    else
        cout << "2\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}