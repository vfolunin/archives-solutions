#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    cin >> s;

    if (s == "#")
        return 0;

    s.back() = '0' + ((count(s.begin(), s.end(), '1') % 2) ^ (s.back() == 'o'));

    cout << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}