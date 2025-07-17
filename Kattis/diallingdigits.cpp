#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

string getButtons(string &s) {
    static string buttons = "22233344455566677778889999";
    string res;
    for (char c : s)
        res += buttons[c - 'a'];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount, queryCount;
    cin >> wordCount >> queryCount;

    unordered_map<string, set<string>> words;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        words[getButtons(word)].insert(word);
    }

    for (int i = 0; i < queryCount; i++) {
        string buttons;
        cin >> buttons;

        cout << words[buttons].size();
        for (const string &word : words[buttons])
            cout << " " << word;
        cout << "\n";
    }
}