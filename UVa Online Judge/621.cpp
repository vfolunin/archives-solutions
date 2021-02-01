#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s == "1" || s == "4" || s == "78")
        cout << "+\n";
    else if (s[s.size() - 2] == '3' && s.back() == '5')
        cout << "-\n";
    else if (s.front() == '9' && s.back() == '4')
        cout << "*\n";
    else
        cout << "?\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}