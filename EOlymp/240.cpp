#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

string normalize(string &s) {
    unordered_map<char, char> code;
    for (char &c : s) {
        if (!code.count(c))
            code[c] = 'a' + code.size();
        c = code[c];
    }
    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_set<string> normalizedStrings;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        normalizedStrings.insert(normalize(s));
    }

    cout << normalizedStrings.size();
}