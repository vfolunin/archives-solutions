#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

bool can(string &s, int size) {
    unordered_set<string> seen;
    for (int i = 0; i + size <= s.size(); i++) {
        string substring = s.substr(i, size);
        if (seen.count(substring))
            return 0;
        seen.insert(substring);
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s >> s;

    int l = 0, r = s.size();
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(s, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}