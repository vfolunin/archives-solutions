#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string readLetters() {
    string s;
    cin >> s;

    for (char &c : s)
        c = tolower(c);

    sort(s.begin(), s.end());
    return s;
}

void solve() {
    string a = readLetters();
    string b = readLetters();

    cout << (a == b ? "Yes\n" : "No\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}