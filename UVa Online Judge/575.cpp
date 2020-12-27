#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool solve() {
    string s;
    cin >> s;

    if (s == "0")
        return 0;

    long long res = 0;
    for (int i = 0; i < s.size(); i++)
        res += (s[i] - '0') * ((1LL << (s.size() - i)) - 1);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}