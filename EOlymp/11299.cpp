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
    for (string s; cin >> s; )
        a.push_back(s);

    stable_sort(a.begin(), a.end(), [](const string &lhs, const string &rhs) {
        if (lhs == "ADAUniversity" || rhs == "ADAUniversity")
            return lhs == "ADAUniversity" && rhs != "ADAUniversity";
        return lexicographical_compare(lhs.rbegin(), lhs.rend(), rhs.rbegin(), rhs.rend());
    });

    for (string &s : a)
        cout << s << "\n";
}