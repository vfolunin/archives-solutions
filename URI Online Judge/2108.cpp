#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords() {
    string line;
    getline(cin, line);

    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word)
        words.push_back(word);

    return words;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string biggestWord;

    while (1) {
        vector<string> words = readWords();
        if (words[0] == "0")
            break;

        for (int i = 0; i < words.size(); i++) {
            if (biggestWord.size() <= words[i].size())
                biggestWord = words[i];
            cout << words[i].size() << (i + 1 < words.size() ? "-" : "\n");
        }
    }

    cout << "\nThe biggest word: " << biggestWord << "\n";
}