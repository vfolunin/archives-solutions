#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int an, bn;
    cin >> an >> bn;
    cin.ignore();

    vector<string> a(an);
    for (string &s : a)
        getline(cin, s);

    vector<string> b(bn);
    for (string &s : b)
        getline(cin, s);

    unordered_set<string> s;
    for (string &sa : a)
        for (string &sb : b)
            s.insert(sa + sb);

    cout << "Case " << test << ": " << s.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}