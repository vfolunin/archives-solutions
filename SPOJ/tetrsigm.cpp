#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    cin >> s;

    vector<int> sep;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '/' || s[i] == ':')
            sep.push_back(i);
    sep.push_back(s.size());

    cout << "Case #" << test << ": " << s.substr(sep[2] + 1, sep[3] - sep[2] - 1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}