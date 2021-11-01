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

    set<char> letters;
    for (char c : line)
        if (isalpha(c))
            letters.insert(tolower(c));

    if (letters.size() == 26)
        cout << "frase completa\n";
    else if (letters.size() >= 13)
        cout << "frase quase completa\n";
    else
        cout << "frase mal elaborada\n";
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