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

    vector<string> words = readWords();

    for (string &word : words)
        if (word.size() >= 4 && word[0] == word[2] && word[1] == word[3])
            word = word.substr(2);
    
    for (int i = 0; i < words.size(); i++)
        cout << words[i] << (i + 1 < words.size() ? " " : "\n");
}