#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    set<char> symbols;
    for (int i = 0; i < 3; i++) {
        char c;
        cin >> c;
        symbols.insert(c);
    }

    string s;
    cin >> s;

    set<char> missingSymbols;
    for (char c : s)
        if (!symbols.count(c))
            missingSymbols.insert(c);

    cout << missingSymbols.size();
}