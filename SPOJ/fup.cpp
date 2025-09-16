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

    string sortedS = s;
    sort(sortedS.begin(), sortedS.end());

    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res += s[i] == sortedS[i];

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}