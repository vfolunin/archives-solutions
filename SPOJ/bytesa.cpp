#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    getline(cin, s);

    if (s == "END")
        return 0;

    vector<int> count(26);
    for (char c : s)
        if (c != ' ')
            count[c - 'A']++;

    if (*max_element(count.begin(), count.end()) <= 1)
        cout << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}