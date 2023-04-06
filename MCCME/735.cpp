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
    string s;
    while (cin >> s)
        a.push_back(s);

    sort(a.begin(), a.end(), [](string &lhs, string &rhs) {
        return lhs + rhs > rhs + lhs;
    });

    for (string &s : a)
        cout << s;
}