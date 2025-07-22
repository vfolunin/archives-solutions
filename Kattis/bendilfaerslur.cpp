#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line, const string &separators) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (separators.find(c) == -1) {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);
    return words;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    if (s.find('.') != -1) {
        vector<string> parts = split(s, ".");
        reverse(parts.begin(), parts.end());

        for (string &part : parts)
            cout << part << ".";
        cout << "in-addr.arpa.";
    } else {
        vector<string> parts = split(s, ":");
        int index = find(parts.begin(), parts.end(), "") - parts.begin();
        while (parts.size() < 8)
            parts.insert(parts.begin() + index, "");
        reverse(parts.begin(), parts.end());

        for (string &part : parts) {
            part = string(4 - part.size(), '0') + part;
            reverse(part.begin(), part.end());
            for (char c : part)
                cout << c << ".";
        }
        cout << "ip6.arpa.";
    }
}