#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    static string vowels = "aeiouy";
    return vowels.find(c) != -1;
}

bool solve() {
    string s;
    cin >> s;

    if (s == "quit!")
        return 0;

    if (s.size() > 4 && !isVowel(s[s.size() - 3]) && s[s.size() - 2] == 'o' && s.back() == 'r')
        cout << s.substr(0, s.size() - 2) << "our\n";
    else
        cout << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}