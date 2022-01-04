#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool endsWith(const string &s, const string &t) {
    if (s.size() < t.size())
        return 0;

    for (int i = 0; i < t.size(); i++)
        if (s[s.size() - 1 - i] != t[t.size() - 1 - i])
            return 0;

    return 1;
}

bool solve() {
    string word;
    if (!(cin >> word))
        return 0;

    int width = 0;
    while (!endsWith(word.substr(0, width), word.substr(width)))
        width++;

    cout << word.substr(0, width) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}