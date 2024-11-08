#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<string> a;
    for (string s; ss >> s; )
        a.push_back(s);

    stable_sort(a.begin(), a.end(), [](const string &lhs, const string &rhs) {
        return lhs.size() < rhs.size();
    });

    for (string &s : a)
        cout << s << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.get();

    for (int i = 0; i < n; i++)
        solve();
}