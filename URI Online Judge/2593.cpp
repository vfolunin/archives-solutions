#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prefixFunction(const string &s) {
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && s[i] != s[border])
            border = p[border - 1];
        p[i] = border + (s[i] == s[border]);
    }
    return p;
}

vector<int> find(const string &text, const string &word) {
    vector<int> p = prefixFunction(" " + word + " # " + text + " "), pos;
    for (int i = 0; i < p.size(); i++)
        if (p[i] == word.size() + 2)
            pos.push_back(i - word.size() * 2 - 4);
    return pos;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text;
    getline(cin, text);

    int wordCount;
    cin >> wordCount;

    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        
        vector<int> pos = find(text, word);
        if (pos.empty()) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < pos.size(); i++)
                cout << pos[i] << (i + 1 < pos.size() ? " " : "\n");
        }
    }
}