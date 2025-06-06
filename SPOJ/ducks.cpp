#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string text;
    getline(cin, text);

    unordered_set<char> word = { 'D', 'u', 'c', 'k', 'y' }, found;
    for (char c : text) {
        if (word.count(c))
            found.insert(c);
        else if (c != '.')
            break;
    }

    if (word == found)
        cout << "DUCKY IS HERE!\n";
    else
        cout << "NO DUCKY!\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}