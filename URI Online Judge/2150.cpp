#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string vowels, text;
    if (!getline(cin, vowels) || !getline(cin, text))
        return 0;
    
    set<char> vowelSet(vowels.begin(), vowels.end());

    int res = 0;
    for (char c : text)
        res += vowelSet.count(c);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}