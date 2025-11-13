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
    for (int i = 0; i < s.size(); i++)
        res += s[i] == '2' && (i + 1 == s.size() || s[i + 1] != '5');

    cout << res;
}