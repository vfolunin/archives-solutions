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

    int res;
    string s;
    cin >> res >> res >> s;

    for (int i = 0; i < s.size(); i++)
        res -= !i && s[i] == 'R' || i && s[i - 1] == s[i];

    cout << max(res, 0);
}