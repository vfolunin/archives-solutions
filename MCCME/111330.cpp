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

    while (getline(cin, s))
        a.push_back(string(s.rbegin(), s.rend()));

    reverse(a.begin(), a.end());

    for (string &s : a)
        cout << "\n" << s;
    cout << "\n";
}