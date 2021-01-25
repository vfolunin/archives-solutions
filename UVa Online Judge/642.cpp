#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    map<string, set<string>> words;
    while (1) {
        string word;
        if (!(cin >> word))
            return 0;

        if (word == "XXXXXX")
            break;

        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        words[sortedWord].insert(word);
    }

    while (1) {
        string sortedWord;
        cin >> sortedWord;

        if (sortedWord == "XXXXXX")
            return 1;
        
        sort(sortedWord.begin(), sortedWord.end());

        if (!words.count(sortedWord)) {
            cout << "NOT A VALID WORD\n";
        } else {
            for (const string &word : words[sortedWord])
                cout << word << "\n";
        }
        cout << "******\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}