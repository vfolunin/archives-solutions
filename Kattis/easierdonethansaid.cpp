#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    static const string vowels = "aeiou";
    return vowels.find(c) != -1;
}

bool solve() {
    string s;
    cin >> s;

    if (s == "end")
        return 0;

    cout << "<" << s << "> is ";

    bool hasVowel = 0;
    string types = "???";

    for (int i = 0; i < s.size(); i++) {
        types = types.substr(1) + (char)(isVowel(s[i]) + '0');
        hasVowel |= types.back() == '1';
        if (types == "000" || types == "111" || (i && s[i - 1] == s[i] && s[i] != 'o' && s[i] != 'e')) {
            cout << "not acceptable.\n";
            return 1;
        }
    }

    cout << (hasVowel ? "" : "not ") << "acceptable.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}