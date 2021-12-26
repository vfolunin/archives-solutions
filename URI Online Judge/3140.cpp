#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool endsWith(string &s, const string &t) {
    if (s.size() < t.size())
        return 0;

    for (int i = 0; i < t.size(); i++)
        if (s[s.size() - 1 - i] != t[t.size() - 1 - i])
            return 0;

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;

    while (1) {
        getline(cin, line);
        if (endsWith(line, "<body>"))
            break;
    }

    while (1) {
        getline(cin, line);
        if (endsWith(line, "</body>"))
            break;
        cout << line << "\n";
    }
}