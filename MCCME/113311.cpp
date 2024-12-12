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

    vector<string> a;
    for (string s; getline(cin, s); )
        a.push_back(s);

    int res = 0;
    for (string &s : a)
        for (int i = 1; i < s.size(); i++)
            res += s[i - 1] == '\\' && (s[i] == 'n' || s[i] == 'r' || s[i] == 't');

    cout << res;
}