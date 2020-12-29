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

    int a[2] = {};
    for (int i = 0; i < s.size(); i++)
        a[i % 2] += s[i] - '0';

    cout << s << " is ";
    if ((a[0] - a[1]) % 11)
        cout << "not ";
    cout << "a multiple of 11.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}