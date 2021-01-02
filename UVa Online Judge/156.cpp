#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    map<string, vector<string>> anagrams;

    while (1) {
        string word;
        cin >> word;

        if (word == "#")
            break;

        string sortedWord;
        for (char c : word)
            sortedWord += tolower(c);
        sort(sortedWord.begin(), sortedWord.end());
        anagrams[sortedWord].push_back(word);
    }

    vector<string> ananagrams;
    for (auto &[sortedWord, words] : anagrams)
        if (words.size() == 1)
            ananagrams.push_back(words[0]);
    sort(ananagrams.begin(), ananagrams.end());

    for (string &word : ananagrams)
        cout << word << "\n";
}