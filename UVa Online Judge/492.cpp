#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string pigLatin(string &s) {
    static const string VOWELS = "aeiou";
    if (VOWELS.find(tolower(s[0])) != -1)
        return s + "ay";
    return s.substr(1) + s[0] + "ay";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string word;
    char c;
    while (cin >> noskipws >> c) {
        if (isalpha(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                cout << pigLatin(word);
                word.clear();
            }
            cout << c;            
        }
    }
    if (!word.empty())
        cout << pigLatin(word);
}