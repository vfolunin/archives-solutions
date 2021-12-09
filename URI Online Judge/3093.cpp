#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string cards;
    cin >> cards;

    set<char> charSet(cards.begin(), cards.end());
    string chars = "JQKA";

    for (char c : chars) {
        if (!charSet.count(c)) {
            cout << "Ooo raca viu\n";
            return;
        }
    }
    cout << "Aaah muleke\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}