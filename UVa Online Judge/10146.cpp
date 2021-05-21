#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int lcp(string &a, string &b) {
    int p = 0;
    while (p < a.size() && p < b.size() && a[p] == b[p])
        p++;
    return p;
}

void solve(int test) {
    if (test)
        cout << "\n";

    string prevLine;
    int spaceCount = 0;
    while (1) {
        string line;
        getline(cin, line);

        if (line.empty())
            break;

        spaceCount = min(spaceCount + 1, lcp(prevLine, line));
        cout << string(spaceCount, ' ') << line << "\n";
        prevLine = line;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}