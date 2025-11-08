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

    string t = "pusheen";
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res += s[i] != t[i];

    cout << res << "\n";
}