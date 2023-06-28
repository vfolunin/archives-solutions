#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int get(const string &s, int i) {
    return i < s.size() ? s[i] : '0';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i;
    cin >> i;
    i--;

    vector<string> a;
    for (string s; cin >> s; )
        a.push_back(s);

    stable_sort(a.begin(), a.end(), [&](const string &lhs, const string &rhs) {
        return get(lhs, i) < get(rhs, i);
    });

    for (string &s : a)
        cout << s << " ";
}