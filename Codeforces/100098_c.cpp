#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("computer.in", "r", stdin);
    freopen("computer.out", "w", stdout);

    string s;
    cin >> s;

    int res = s[0] - '0';
    for (int i = 1; i < s.size(); i++)
        res += s[i - 1] != s[i];

    cout << res;
}