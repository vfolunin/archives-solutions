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
    cin >> s >> s;

    int res = 0;
    for (int i = 1; i < s.size(); i++)
        res += s[i - 1] != s[i];
    res += s.back() == '1';

    cout << res;
}