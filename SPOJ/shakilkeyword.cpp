#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string line;
    getline(cin, line);
    line += " ";

    int found = 0;
    string word, delimiters = "|$ *@.&\\\"!^,?";
    for (char c : line) {
        if (delimiters.find(c) == -1) {
            word += c;
        } else {
            if (word.find('#') != -1) {
                found = 1;
                cout << word << "\n";
            }
            word.clear();
        }
    }

    if (!found)
        cout << "No keywords.\n";
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