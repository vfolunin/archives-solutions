#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toLower(string s) {
    for (char &c : s)
        c = tolower(c);
    return s;
}

string getReplace(string &word, string &pattern, string &replace) {
    if (toLower(word) != pattern)
        return word;
    if (islower(word[0]))
        return replace;
    string res = replace;
    res[0] = toupper(res[0]);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string pattern, replace;
    cin >> pattern >> replace >> noskipws;
    cin.get();

    pattern = toLower(pattern);
    replace = toLower(replace);

    string word;
    for (char c; cin >> c; ) {
        if (isalpha(c)) {
            word += c;
        } else {
            cout << getReplace(word, pattern, replace) << c;
            word.clear();
        }
    }
    cout << getReplace(word, pattern, replace);
}