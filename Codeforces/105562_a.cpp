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

    int size;
    cin >> size;
    cin.ignore();

    vector<string> a(size);
    for (string &s : a)
        getline(cin, s);

    sort(a.begin(), a.end(), [](string &lhs, string &rhs) {
        return lexicographical_compare(
            find_if(lhs.begin(), lhs.end(), [](char c) { return (bool)isupper(c); }), lhs.end(),
            find_if(rhs.begin(), rhs.end(), [](char c) { return (bool)isupper(c); }), rhs.end()
        );
    });

    for (string &s : a)
        cout << s << "\n";
}