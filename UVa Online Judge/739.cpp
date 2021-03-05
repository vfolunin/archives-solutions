#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string word;
    if (!(cin >> word))
        return 0;

    static string letters = "AEIOUYWHBPFVCSKGJQXZDTLMNR";
    static string codes   = "--------111122222222334556";

    string soundex;
    for (char letter : word)
        soundex.push_back(codes[letters.find(letter)]);

    soundex.erase(unique(soundex.begin(), soundex.end()), soundex.end());
    soundex.erase(remove(soundex.begin() + 1, soundex.end(), '-'), soundex.end());
    soundex += "000";
    soundex = word[0] + soundex.substr(1, 3);

    cout << string(9, ' ') << setw(25) << left << word << soundex << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << string(9, ' ') << setw(25) << left << "NAME" << "SOUNDEX CODE\n";
    while (solve());
    cout << string(19, ' ') << "END OF OUTPUT\n";
}