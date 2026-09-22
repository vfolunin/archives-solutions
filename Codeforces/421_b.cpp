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

    bool ok = s == string(s.rbegin(), s.rend());
    string letters = "AHIMOTUVWXY";
    for (char c : s)
        ok &= letters.find(c) != -1;

    cout << (ok ? "YES" : "NO");
}