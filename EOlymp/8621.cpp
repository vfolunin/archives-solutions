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

    sort(s.begin(), s.end());

    if (s[0] == s[1] && s[1] != s[2] && s[2] == s[3])
        cout << "YES";
    else
        cout << "NO";
}