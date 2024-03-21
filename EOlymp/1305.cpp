#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    sort(a.begin(), a.end(), [](string &lhs, string &rhs) {
        return lhs + rhs > rhs + lhs;
    });

    for (string &s : a)
        cout << s;
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}