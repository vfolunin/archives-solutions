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

    int res = 0;
    for (int i = 0; i + 5 <= s.size(); i++)
        res += s[i] == s[i + 4] && s[i + 1] == s[i + 3];

    cout << res;
}