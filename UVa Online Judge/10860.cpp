#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool contains(string &s, int to, string &part) {
    for (int i = to, j = part.size() - 1; j >= 0; i--, j--)
        if (s[i] != part[j])
            return 0;
    return 1;
}

void solve(int test) {
    string s;
    cin >> s;

    int partCount;
    cin >> partCount;

    vector<string> parts;
    for (int i = 0; i < partCount; i++) {
        string part;
        cin >> part;
        parts.push_back(part);
        reverse(part.begin(), part.end());
        parts.push_back(part);
    }

    vector<int> minParts(s.size() + 1, 1e9);
    minParts[0] = 0;

    for (int i = 1; i <= s.size(); i++)
        for (string &part : parts)
            if (i >= part.size() && contains(s, i - 1, part))
                minParts[i] = min(minParts[i], minParts[i - part.size()] + 1);
     
    cout << "Set " << test << ": ";
    if (minParts.back() != 1e9)
        cout << minParts.back() << ".\n";
    else
        cout << "Not possible.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}